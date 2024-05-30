# Controle Universal 2 motores ESP-32 v1.0
Controle universal para robôs com 2 motores de movimento utilizando esp-32.

O controle pode ser qualquer dispositivo que consiga usar um navegador.\
Os unicos navegadores testados são [Safari](https://pt.wikipedia.org/wiki/Safari_(navegador)) e [Firefox](https://pt.wikipedia.org/wiki/Mozilla_Firefox).\
 \
Claro, aqui está uma revisão aprimorada do texto:

O objetivo deste controle é reduzir os custos associados à montagem do robô de batalha do IFES. Destinado ao modelo básico do robô, ele serve como uma plataforma inicial que pode ser facilmente adaptada às necessidades do usuário. Com ênfase na legibilidade e na abstração das rotinas de nível mais baixo, o código fornecido acima deve ser considerado como um ponto de partida, onde apenas a identificação precisa ser configurada. Além disso, é facilmente extensível para aqueles que desejam um controle mais avançado e com mais funcionalidades.

Este projeto utiliza a framework ESP-IDF, desenvolvida pelos criadores do ESP32, e é completamente open-source. Isso significa que o código é disponibilizado livremente para uso, modificação e distribuição. Além disso, a ESP-IDF é multiplataforma, oferecendo suporte para Linux, Windows e macOS. O uso do Python como linguagem de script torna-o ainda mais acessível, permitindo sua execução em diferentes sistemas operacionais.

Por meio dessa abordagem, buscamos não apenas fornecer uma solução econômica para a construção do robô, mas também promover a acessibilidade e a flexibilidade, permitindo que os usuários personalizem e ampliem o controle de acordo com suas necessidades específicas.
# Para instalar o controle no esp-32 digite os seguintes comandos.
## Linux (Based on Arch-Linux)
Primeiro temos que instalar o ESP-IDF no seu sistema.
```bash
$  git clone --recursive https://github.com/espressif/esp-idf.git
```
Isso vai clonar o repositorio da esp-idf e todos seus intra repositorios, que são os módulos basicamente. \
    \
Após isso você vai escrever:
```bash
$  cd esp-idf/ \
```
```bash
$  ./install.sh \
```
```bash
$  . ./export.sh \
```
```bash
$  git clone https://github.com/ArthurFabris/esp32-wifi-controller.git
```
```bash
$  idf.py create-project NOME_DO_PROJETO\
```
```bash
$  cp /caminho/absoluto/para/esp32-wifi-controller/src/ /caminho/absoluto/para/NOME_DO_PROJETO\
```
Após isso é só conectar o ESP-32 com um cabo USB no seu computador e executar o seguinte comando:
```bash
$  idf.py build flash monitor\
```
Isso vai compilar, gravar e monitorar o seu codigo.\
    \
Se tudo funcionar você vera que uma rede wifi foi criada com o nome que você escolheu.\
     
Para se conectar com o robô basta se conectar na rede wifi criada e após isso digitar:\
```https
192.168.4.1\
```
Que é o linh do servidor https criado pelo robô.\
     \
Se tudo der certo você verá a seguinte imagem:\
![image](https://github.com/ArthurFabris/esp32-wifi-controller/assets/151470840/3f1b1b04-6652-48c8-a08b-711ca6f2b39b)\
Agora é só controlar o robô e ajustar o codigo para a sua preferencia.

## Windows 10 e 11

Ainda a ser implementado, pretendo fazer em uma VM e testar, e tambem em um computador do proprio IFES.
## MAC-OS
Só vai ser implementado se alguma pessoa conseguir compilar o codigo e gravar no esp32, não tenho acesso a produtos apple e n quero fzr um hackintosh.


Qualquer duvida, sugestão entre em contato com: arthurfabris001@gmail.com ou deixem um comentario na propria pagina do github ou faça um commit!



