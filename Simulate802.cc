#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/mobility-module.h"
#include "ns3/wifi-module.h"
#include "ns3/internet-module.h"
#include "ns3/flow-monitor-module.h"
#include "ns3/on-off-helper.h"

using namespace ns3;

int main(int argc, char *argv[]) {
    CommandLine cmd;
    cmd.Parse(argc, argv);

    // Configuração do padrão WiFi (802.11n ou 802.11ax)
    bool is80211ax = false; // Alterne para falso para 802.11n
    std::string wifiStandard = is80211ax ? "802.11ax" : "802.11n";

    // Criação de nós
    NodeContainer wifiStaNodes, wifiApNode;
    wifiStaNodes.Create(10); // Nós STA = dispositivos móveis, laptops, etc... usuários da rede
    wifiApNode.Create(1); // Nó APA = ponto de acesso wifi

    // Configuração do WiFi
    WifiHelper wifi;
    if (is80211ax) {
        wifi.SetStandard(WIFI_STANDARD_80211ax);
    } else {
        wifi.SetStandard(WIFI_STANDARD_80211n);
    }

    // Características do canal wifi
    YansWifiChannelHelper channel = YansWifiChannelHelper::Default();
    YansWifiPhyHelper phy;
    phy.SetChannel(channel.Create());
    
    
    // Configuração do MAC para todos dispositivos da rede
    WifiMacHelper mac;
    Ssid ssid = Ssid("ns3-wifi");

    mac.SetType("ns3::StaWifiMac", "Ssid", SsidValue(ssid), "ActiveProbing", BooleanValue(false));
    NetDeviceContainer staDevices = wifi.Install(phy, mac, wifiStaNodes);

    mac.SetType("ns3::ApWifiMac", "Ssid", SsidValue(ssid));
    NetDeviceContainer apDevice = wifi.Install(phy, mac, wifiApNode);

    // Mobilidade - Configuração para as estações móveis (STA), podendo elas se mover dentro de um retângulo 100x100
    MobilityHelper staMobility;
    staMobility.SetPositionAllocator("ns3::GridPositionAllocator",
                                     "MinX", DoubleValue(50.0),
                                     "MinY", DoubleValue(80.0),
                                     "DeltaX", DoubleValue(10.0), // Espaço horizontal entre dispositivos
                                     "DeltaY", DoubleValue(10.0), // Espaço vertical entre dispositivos
                                     "GridWidth", UintegerValue(5), // Número de dispositivos por linha
                                     "LayoutType", StringValue("RowFirst"));
    staMobility.SetMobilityModel("ns3::RandomWalk2dMobilityModel",
                                 "Bounds", RectangleValue(Rectangle(0, 200, 0, 200)));
    staMobility.Install(wifiStaNodes);

    // Mobilidade - Configuração para o AP, o ponto de acesso não se move, permanecendo fixo como uma torre em um local.
    MobilityHelper apMobility;
    apMobility.SetPositionAllocator("ns3::GridPositionAllocator",
                                    "MinX", DoubleValue(70.0),
                                    "MinY", DoubleValue(65.0),
                                    "DeltaX", DoubleValue(0.0),
                                    "DeltaY", DoubleValue(0.0),
                                    "GridWidth", UintegerValue(1),
                                    "LayoutType", StringValue("RowFirst"));
    apMobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
    apMobility.Install(wifiApNode);

    // Configura a pilha de protocolos de internet (IP, UDP, TCP)
    InternetStackHelper stack;
    stack.Install(wifiStaNodes);
    stack.Install(wifiApNode);

    // Atribuição de endereços IP aos dispositivos
    Ipv4AddressHelper address;
    address.SetBase("192.168.1.0", "255.255.255.0");
    Ipv4InterfaceContainer staInterfaces = address.Assign(staDevices);
    Ipv4InterfaceContainer apInterface = address.Assign(apDevice);

    // Imprima a frequência e canal configurados
    Ptr<WifiNetDevice> apNetDevice = apDevice.Get(0)->GetObject<WifiNetDevice>();
    Ptr<WifiPhy> phyAp = apNetDevice->GetPhy();
    std::cout << "Access Point Frequency: " << phyAp->GetFrequency() << " MHz" << std::endl;

    Ptr<WifiNetDevice> staNetDevice = staDevices.Get(0)->GetObject<WifiNetDevice>();
    Ptr<WifiPhy> phySta = staNetDevice->GetPhy();
    std::cout << "Station Frequency: " << phySta->GetFrequency() << " MHz" << std::endl;



    // Aplicativos de tráfego - Envia pacotes UDP
    uint16_t port = 9;
    OnOffHelper onOff("ns3::UdpSocketFactory", InetSocketAddress(apInterface.GetAddress(0), port));
    onOff.SetAttribute("DataRate", DataRateValue(DataRate("5Mbps"))); // Taxa de envio dos pacots
    onOff.SetAttribute("PacketSize", UintegerValue(1024)); // Tamanho dos pacotes

    ApplicationContainer app = onOff.Install(wifiStaNodes);
    app.Start(Seconds(1.0));
    app.Stop(Seconds(14.0));

    // Monitoramento de fluxo
    FlowMonitorHelper flowmon;
    Ptr<FlowMonitor> monitor = flowmon.InstallAll();

    // Execução da simulação
    Simulator::Stop(Seconds(15.0));
    Simulator::Run();

    // Exportação de resultados para XML
    monitor->SerializeToXmlFile(wifiStandard + "-results.xml", true, true);

    Simulator::Destroy();
    return 0;
}

