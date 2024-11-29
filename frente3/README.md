# Execução da Simulação dos modelos IEEE 802.11
O arquivo presente nesta branch, com nome " Simulate802.cc " contém todas as informações, através de comentários no código de como foi feita a simulação.

## Resultados
Cada simulação gera um arquivo com o nome do modelo + results.xml, os arquivos referentes à simulação feita e descrita neste trabalho também estão presentes nesta branch, com seus nomes respectivos. Os arquivos result.xml podem ser lidos através do código python nomeado `leitura.py`. Se você quiser ver os resultados obtidos através da simulação do modelo 802.11ax, por exemplo, é necessário:

Configurar a simulação através do arquivo `Simulate802.cc` e rodar a simulação com o comando em um terminal dentro da pasta onde seu simulador está instalado:
```
./ns3 run caminho_do_arquivo/Simulate802.cc
```
Um arquivo _802.11ax-results.xml_ será gerado na mesma pasta do simulador. Esse arquivo então, para ser lido, é preciso ser informado junto do arquivo de leitura através de um comando python (lembre-se que ambos arquivos, de leitura e xml devem estar dentro do mesmo diretório).;
```
python3 leitura.py 802.11ax-results.xml
```
