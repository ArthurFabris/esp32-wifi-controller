# Controle Universal 2 motores ESP-32 v1.0.
![Python](https://img.shields.io/badge/Python-3.12.3%2B-blue)
![Git](https://img.shields.io/badge/Git-2.45.1-blue)
![Windows Compatibility](https://img.shields.io/badge/Windows-10-blue)
![Linux Compatibility](https://img.shields.io/badge/Linux-Compatible-blue)
![Arch Linux Compatibility](https://img.shields.io/badge/Arch-Linux-blue)
![ESP-IDF](https://img.shields.io/badge/ESP--IDF-v5.4-red)




Controle universal para robôs com 2 motores de movimento utilizando esp-32.
### TO-DO LIST

- [x] Adicionar botão da arma e inversão de eixos. (Tópico será removido após 7d)
- [x] Exemplificar a construção do e flash do programa em Windows. (Tópico será removido após 7d).
- [ ] Fazer script de instalação automatica para Linux.
- [ ] Fazer script de instalação automatica para Windows.


- O controle pode ser qualquer dispositivo que consiga usar um navegador.
- Os unicos navegadores testados são [Safari](https://pt.wikipedia.org/wiki/Safari_(navegador)) e [Firefox](https://pt.wikipedia.org/wiki/Mozilla_Firefox). Safari no Iphone7 e Firefox no Arch Linux.

### Vantagens desse controle sobre o arduino + radio:
- Multiplos controles simultaneos.\
  • Isso torna possivel mais de um piloto, desbloqueando novas estrategias de combate.
- Menor custo.
- Mais customizavel.
- Mais simples.



O objetivo deste controle é reduzir os custos associados à montagem do robô de batalha do IFES. Destinado ao modelo básico do robô, ele serve como uma plataforma inicial que pode ser facilmente adaptada às necessidades do usuário. Com ênfase na legibilidade e na abstração das rotinas de nível mais baixo, o código fornecido acima deve ser considerado como um ponto de partida, onde apenas a identificação precisa ser configurada. Além disso, é facilmente extensível para aqueles que desejam um controle mais avançado e com mais funcionalidades.



Este projeto utiliza a framework ESP-IDF, desenvolvida pelos criadores do ESP32, e é completamente open-source. Isso significa que o código é disponibilizado livremente para uso, modificação e distribuição. Além disso, a ESP-IDF é multiplataforma, oferecendo suporte para Linux, Windows e macOS. O uso do Python como linguagem de script torna-o ainda mais acessível, permitindo sua execução em diferentes sistemas operacionais.



Por meio dessa abordagem, buscamos não apenas fornecer uma solução econômica para a construção do robô, mas também promover a acessibilidade e a flexibilidade, permitindo que os usuários personalizem e ampliem o controle de acordo com suas necessidades específicas.
# Linux (Based on Arch-Linux)
### Arch linux:
- Primeiro temos que instalar o git.
```bash
sudo pacman -S git
```
- Agora temos que instalar o python 3.12, para isso vamos usar o pyenv.
```bash
sudo pacman -S pyenv
```
```bash
export PATH="$HOME/.pyenv/bin:$PATH"
eval "$(pyenv init --path)"
eval "$(pyenv init -)"
```
```bash
pyenv install 3.12.3
```
```bash
pyenv install 3.12.3
```
```bash
pyenv global 3.12.3
```
### Ubuntu
- Primeiro temos que instalar o git.

```bash
sudo apt update
sudo apt install -y git
```

- Agora temos que instalar o python 3.12, para isso vamos usar o pyenv.
```bash
sudo apt install -y make build-essential libssl-dev zlib1g-dev libbz2-dev libreadline-dev libsqlite3-dev wget curl llvm libncurses5-dev libncursesw5-dev xz-utils tk-dev libffi-dev liblzma-dev python-openssl git
curl https://pyenv.run | bash
```
```bash
export PATH="$HOME/.pyenv/bin:$PATH"
eval "$(pyenv init --path)"
eval "$(pyenv init -)"
```
```bash
pyenv install 3.12.3
```
```bash
pyenv install 3.12.3
```
```bash
pyenv global 3.12.3
```
## Agora temos que instalar o ESP-IDF no seu sistema.
Como as ferramentas usadas a partir de agora devem ser as mesmas, o tutorial se torna universal para as Distros de Linux.
```bash
git clone --recursive https://github.com/espressif/esp-idf.git
```
Isso vai clonar o repositorio da esp-idf e todos seus intra repositorios, que são os módulos basicamente.


- Após isso você vai escrever:
```bash
cd esp-idf/
```
```bash
./install.sh
```
```bash
. ./export.sh
```
```bash
git clone https://github.com/ArthurFabris/esp32-wifi-controller.git
```
```bash
idf.py create-project NOME_DO_PROJETO\
```
```bash
cp /caminho/absoluto/para/esp32-wifi-controller/src/ /caminho/absoluto/para/NOME_DO_PROJETO
```
- !!! Edite o CMakeLists.txt e coloque o nome do seu projeto. !!!
- Após isso é só conectar o ESP-32 com um cabo USB no seu computador e executar o seguinte comando:
```bash
idf.py fullclean
```
```bash
idf.py build flash monitor
```
Isso vai compilar, gravar e monitorar o seu codigo.



## Windows 10 e 11
- Baixe o Python 3.12 usando o link: [Python](https://www.python.org/ftp/python/3.12.3/python-3.12.3-amd64.exe)
- Ou visite o site do Python: [Python website](https://www.python.org/downloads/windows/)
- Baixe o git usando o seguinte link: [Git](https://github.com/git-for-windows/git/releases/download/v2.45.1.windows.1/Git-2.45.1-64-bit.exe)
- Ou visite o site do git: [Git website](https://git-scm.com/download/win)
- Execute o instalador do Python, selecione a opção de adicionar o python para o PATH.
- Clique next até concluir.
- Execute o instalador do GIT.
- Clique next até concluir.
- Após isso aperte win + q e digite "git"
- Execute o "Git CMD".
- Digite:
```cmd
git clone --recursive https://github.com/espressif/esp-idf.git
```
```cmd
cd esp-idf/
```
```cmd
git clone https://github.com/ArthurFabris/esp32-wifi-controller.git
```
- Agora feche o "Git CMD" e abra o CMD.
```cmd
cd C:\\caminho\absoluto\para\esp-idf
```
```cmd
install.bat
```
- Após isso digite:
```cmd
export.bat
```
```cmd
idf.py create-project NOME_DO_PROJETO\
```
- Agora voce pode copiar e colar todos os arquivos da pasta "src" para a pasta NOME_DO_PROJETO usando o explorer.

- !!! Edite o CMakeLists.txt e coloque o nome do seu projeto. !!!

- Após isso digite os seguintes comandos no cmd:
```cmd
cd NOME_DO_PROJETO/
```
```cmd
idf.py fullclean
```
```cmd
idf.py build
```
```cmd
idf.py flash monitor
```


## MAC-OS
Só vai ser implementado se alguma pessoa conseguir compilar o codigo e gravar no esp32, não tenho acesso a produtos apple e n quero fzr um hackintosh.

# Se tudo funcionar você vera que uma rede wifi foi criada com o nome que você escolheu.
     
- Para se conectar com o robô basta se conectar na rede wifi criada e após isso se digitar no navegador:
```https
192.168.4.1
```
Que é o link do servidor https criado pelo robô.


Se surgirem dúvidas ou sugestões, não hesite em entrar em contato através do email: arthurfabris001@gmail.com, deixar um comentário na página do GitHub ou fazer um commit!

Autor: Arthur Fabris.



