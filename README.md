# Robô Explorador Espacial - Etapa 01: Controle Remoto (ESP32)

## Sobre o Projeto
Projeto de um robô explorador espacial desenvolvido para buscar indícios de vida extraterrestre em um planeta simulado. Esta etapa contempla a construção do controle remoto simulado na plataforma Wokwi utilizando a placa ESP32.

## Objetivo da Etapa 01
Mapear a movimentação de um joystick analógico para enviar comandos de direção ao robô, implementar o botão de desligamento remoto de emergência e indicar visualmente o status da conexão através de LEDs operacionais.

## Componentes Utilizados
- 1x Microcontrolador ESP32 DevKit V1
- 1x Joystick Analógico (Eixos X e Y)
- 1x Botão Pushbutton (Parada remota)
- 1x LED Verde (Status: Conectado/Ativo)
- 1x LED Vermelho (Status: Desligado/Desconectado)
- 2x Resistores 220Ω

## Mapeamento de Pinos (Pinout)
- **Joystick VRx:** GPIO 34
- **Joystick VRy:** GPIO 35
- **Botão de Desligar:** GPIO 32
- **LED Verde:** GPIO 18
- **LED Vermelho:** GPIO 19

## Como Executar a Simulação
1. Acesse o projeto simulado no Wokwi através do link abaixo.
2. Inicie a simulação clicando no botão verde de play.
3. Monitore os comandos enviados na aba **Serial Monitor**.
4. Interaja com o Joystick para alternar os comandos de movimentação (`Frente`, `Trás`, `Esquerda`, `Direita`).
5. Pressione o botão para disparar o comando `DESLIGAR`.

## Link do Projeto no Wokwi
- [Acessar Simulação no Velxio](https://velxio.dev/felipe-n-santos/service/)