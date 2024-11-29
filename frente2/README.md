
# Simulação de Redes Móveis com simulador ns-3
Esse projeto foi desenvolvido à fim de por em prática o conteúdo da disciplina de Introdução à Comunicação do curso de Engenharia de Computação da Universidade Federal do Pampa - [(UNIPAMPA)](https://unipampa.edu.br/)

O projeto foi dividido para a turma em grupos de até 4 (quatro) alunos, e os assuntos a serem tratados foram divididos em 3 (três) frentes:

## Frente 1: Preparação de ambiente de Prototipagem
Essa frente consiste na preparação do ambiente para relizar toda a prototipação/relatório do progrma. Cada aluno participante do projeto pode optar por utilizar VSCode, Juyter Notebook, Terminal, ou como quis julgar melhor realizar as prototipações e simulações, sem requisitos propostos.
## Frente 2: Prototipagem com ns-3
As atividades e prototipagens foram feitas baseadas em alguns tutoriais disponibilizados no site oficial do simulador [ns-3](https://www.nsnam.org/), onde os alunos se dividiram entre si para realizar as prototipações que exigiam, na maioria das vezes, entender e alterar partes do código original da plataforma para atender os requisitos solicitados pelo professor da disciplina.

### Atividade 2.1
Aluno responsável: Todo o grupo

Solicitado: Ler os capítulos 1, 2, 4, 5 e 6 do tutorial do [ns-3](https://www.nsnam.org/).

### Atividades 2.2 e 2.5
Aluno responsável: Rafael Vieira Goncalves

Atividade 2.2: Ler e entender o exemplo first.cc e acompanhar a leitura no tutorial do simulador. Objetivos: Realizer envio de dois pacotes de tamanhos diferentes; Realizar mudança na taxa de transmissão.

Atividade 2.5: Fazer e entender o exemplo third.cc e acompanhar a leitura no tutorial do simulador. Objetivos: Realizar o envio de três pacotes de STAs diferentes; Fazer uso do NetAnim ou vis para verificar o movimento dos usuários.


### Atividades 2.3 e 2.4
Aluno responsável: Vitor da Silva Moreira

Atividade 2.3: Objetivo: Ler capítulo 7 do tutorial em[ns-3](https://www.nsnam.org/).

Atividade 2.4: Fazer e entender o exemplo second.cc e acompanhar a leitura no tutorial do simulador. Objetivos: Realizar envio de dois pacotes de tamanhos diferentes sem criar novos objetos; Aumentar número de nós via linha de comando; Fazer uso do tcpdump para insperção de arquivos pcap.


### Atividades 2.6 e 2.7
Aluno responsável: Heitor Mauro Chavez Huarachi

Atividade 2.6: Objetivos: Ler capítulo 8 do tutorial em [ns-3](https://www.nsnam.org/); Mudar modelo de mobilidade, plotar as posições das STAs com o GNUPlot relacionados ao exemplo third.cc da Atividade 2.5; Fazer uso do GNUPlot para visualizar a janela de congestionamento.

Atividade 2.7: Descrever os exemplos sixth.cc e seventh.cc; Gerar o gráfico do seventh.cc; Fazer uso do exemplo rate-adaptation-distance.cc; Descrever o exemplo rate-adaptation-distance.cc; Gerar o gráfico Throughput vs. Distância para os valores padrões do script.

## Frente 3: Redes de Comunicações Móveis
Aluno responsável: Gabriel dos Santos Fredes

Atividade 3.1: Ler e resumir Seção 14.1: IEEE 802.11 Architecture and Services do Livro Wireless Communications Networking (Stallings)

Atividade 3.2: Ler e resumir Seção 14.2: IEEE 802.11 Medium Access Control do Livro Wireless Communications Networking (Stallings)

Atividade 3.3: Ler e resumir Seção 14.3: IEEE 802.11 Physical Layer do Livro Wireless Communications Networking (Stallings)

Atividade 4.4: Criar dois cenários “WIFI 802.11” de simulações com as duas ementas que preferirem (foram utilizados 802.11n vs 802.11ax). Onde exista pelo menos um fluxo de dados em cada dispositivo (pelo menos 5 dispositivos) móvel que está presente na rede simulada. Para esse cenário tente extrair dados como: Atraso (Delay), Variação do atraso (jitter), Perda de pacote(PLR) e taxa de dados(Throughput);
## Instalação

As instruções de instalação e funcionalidades encontram-se no site do próiro simulador, na aba documentação do [ns-3](https://www.nsnam.org/documentation/).
    
### Pós-instalação
Após realizada a instalação conforme documentação do simulador, recomendamos a execução dos seguintes comandos, via terminal, dentro do diretório onde se encontra o simulador:

```
./ns3 clean

./ns3 configure --enable-python-bindings --enable-examples 

./ns3 build
```

## Autores

- [Gabriel dos Santos Fredes](https://github.com/gabsfredes)
- [Heitor Mauro Chavez Huarachi](https://github.com/elcabriton)
- [Rafael Vieira Goncalves](https://github.com/)
- [Vitor da Silva Moreira](https://github.com/)

## Contribuindo

Se desejar contribuir com este projeto, por favor, faça um fork do repositório e envie um pull request com suas alterações.

