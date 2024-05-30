# Controle Universal 2 motores ESP-32 v1.0

Controle universal para robôs com 2 motores de movimento utilizando esp-32.
### TO-DO LIST

- [ ] Adicionar botão da arma e inversão de eixos.
- [ ] Exemplificar a construção do e flash do programa em Windows
- [ ] Fazer script de instalação automatica para Linux
- [ ] Fazer script de instalação automatica para Windows


- O controle pode ser qualquer dispositivo que consiga usar um navegador.
- Os unicos navegadores testados são [Safari](https://pt.wikipedia.org/wiki/Safari_(navegador)) e [Firefox](https://pt.wikipedia.org/wiki/Mozilla_Firefox). Safari no Iphone7 e Firefox no Arch Linux



O objetivo deste controle é reduzir os custos associados à montagem do robô de batalha do IFES. Destinado ao modelo básico do robô, ele serve como uma plataforma inicial que pode ser facilmente adaptada às necessidades do usuário. Com ênfase na legibilidade e na abstração das rotinas de nível mais baixo, o código fornecido acima deve ser considerado como um ponto de partida, onde apenas a identificação precisa ser configurada. Além disso, é facilmente extensível para aqueles que desejam um controle mais avançado e com mais funcionalidades.



Este projeto utiliza a framework ESP-IDF, desenvolvida pelos criadores do ESP32, e é completamente open-source. Isso significa que o código é disponibilizado livremente para uso, modificação e distribuição. Além disso, a ESP-IDF é multiplataforma, oferecendo suporte para Linux, Windows e macOS. O uso do Python como linguagem de script torna-o ainda mais acessível, permitindo sua execução em diferentes sistemas operacionais.



Por meio dessa abordagem, buscamos não apenas fornecer uma solução econômica para a construção do robô, mas também promover a acessibilidade e a flexibilidade, permitindo que os usuários personalizem e ampliem o controle de acordo com suas necessidades específicas.
# Para instalar o controle no esp-32 digite os seguintes comandos.
## Linux (Based on Arch-Linux)
- Primeiro temos que instalar o ESP-IDF no seu sistema.
```bash
$  git clone --recursive https://github.com/espressif/esp-idf.git
```
Isso vai clonar o repositorio da esp-idf e todos seus intra repositorios, que são os módulos basicamente.


- Após isso você vai escrever:
```bash
$  cd esp-idf/
```
```bash
$  ./install.sh
```
```bash
$  . ./export.sh
```
```bash
$  git clone https://github.com/ArthurFabris/esp32-wifi-controller.git
```
```bash
$  idf.py create-project NOME_DO_PROJETO\
```
```bash
$  cp /caminho/absoluto/para/esp32-wifi-controller/src/ /caminho/absoluto/para/NOME_DO_PROJETO
```
- Após isso é só conectar o ESP-32 com um cabo USB no seu computador e executar o seguinte comando:
```bash
$  idf.py build flash monitor
```
Isso vai compilar, gravar e monitorar o seu codigo.\
    \
Se tudo funcionar você vera que uma rede wifi foi criada com o nome que você escolheu.\
     
- Para se conectar com o robô basta se conectar na rede wifi criada e após isso digitar:\
```https
192.168.4.1
```
Que é o link do servidor https criado pelo robô.\
     \
Se tudo der certo você verá a seguinte imagem:\
![image](https://github.com/ArthurFabris/esp32-wifi-controller/assets/151470840/3f1b1b04-6652-48c8-a08b-711ca6f2b39b)\
Agora é só controlar o robô e ajustar o codigo para a sua preferencia.

## Windows 10 e 11

Ainda a ser implementado, pretendo fazer em uma VM e testar, e tambem em um computador do proprio IFES.
## MAC-OS
Só vai ser implementado se alguma pessoa conseguir compilar o codigo e gravar no esp32, não tenho acesso a produtos apple e n quero fzr um hackintosh.

# Layout do circuito de exemplo
![image](https://github.com/ArthurFabris/esp32-wifi-controller/assets/151470840/89d3eb06-5239-4170-8c45-9ee7d7d4631f)
![image](https://github.com/ArthurFabris/esp32-wifi-controller/assets/151470840/6ba34507-cb7c-47d8-b261-81af830b1d0e)


- d4=Verde
- d5=Ciano
- d18=Azul
- d19=Roxo
- d23=Amarelo
- d22=Laranja


O valor do resistor é para ser definido de acordo com a voltagem selecionada.


### Por exemplo:
Para esse circuito, podemos utilizar 5v ou 3.3v e eu estou usando leds de alto brilho.
![image](https://github.com/ArthurFabris/esp32-wifi-controller/assets/151470840/c975ba1e-3430-417e-9940-dbc6fdb8cf70)\
Estes valores representam os cálculos para 5V e 3.3V, juntamente com as fórmulas para que você possa calcular por conta própria.

Se surgirem dúvidas ou sugestões, não hesite em entrar em contato através do email: arthurfabris001@gmail.com, deixar um comentário na página do GitHub ou fazer um commit!

Autor: Arthur Fabris.



