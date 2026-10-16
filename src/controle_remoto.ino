/*
 * Projeto: Controle Remoto - Robô Explorador Espacial
 * Etapa 01: Firmware do ESP32 no Wokwi
 */

// Mapeamento dos Pinos
const int PIN_JOYSTICK_X = 7;
const int PIN_JOYSTICK_Y = 6;
const int PIN_BOTAO_DESLIGAR = 2;
const int PIN_LED_VERDE = 4;
const int PIN_LED_VERMELHO = 5;

// Limiares de leitura para o ADC de 12 bits (0 a 4095)
const int LIMITE_BAIXO = 1000;
const int LIMITE_ALTO = 3000;

// Variáveis de controle de estado
bool roboLigado = true;
String ultimoComando = "";
int ultimoEstadoBotao = HIGH;

void setup() {
  Serial.begin(115200);

  // Configuração dos pinos
  pinMode(PIN_BOTAO_DESLIGAR, INPUT_PULLUP);
  pinMode(PIN_LED_VERDE, OUTPUT);
  pinMode(PIN_LED_VERMELHO, OUTPUT);

  // Status Inicial: Robô Conectado e Ligado
  digitalWrite(PIN_LED_VERDE, HIGH);
  digitalWrite(PIN_LED_VERMELHO, LOW);

  Serial.println("=========================================");
  Serial.println("   CONTROLE REMOTO INICIALIZADO");
  Serial.println("   Status: Conectado | LED Verde ACESO");
  Serial.println("=========================================");
}

void loop() {
  // 1. Leitura do botão de desligamento (com debounce)
  int estadoBotao = digitalRead(PIN_BOTAO_DESLIGAR);
  
  if (estadoBotao == LOW && ultimoEstadoBotao == HIGH) {
    roboLigado = !roboLigado; // Alterna o estado (Ligado/Desligado)
    delay(200); // Debounce simples

    if (!roboLigado) {
      digitalWrite(PIN_LED_VERDE, LOW);
      digitalWrite(PIN_LED_VERMELHO, HIGH);
      Serial.println("Comando enviado: DESLIGAR");
      Serial.println("Status: Robô Desligado | LED Vermelho ACESO");
      ultimoComando = "DESLIGAR";
    } else {
      digitalWrite(PIN_LED_VERDE, HIGH);
      digitalWrite(PIN_LED_VERMELHO, LOW);
      Serial.println("Status: Robô Ligado | LED Verde ACESO");
      ultimoComando = "LIGAR";
    }
  }
  ultimoEstadoBotao = estadoBotao;

  // 2. Leitura e processamento do Joystick (somente se estiver ligado)
  if (roboLigado) {
    int valorX = analogRead(PIN_JOYSTICK_X);
    int valorY = analogRead(PIN_JOYSTICK_Y);
    String comandoAtual = "Parado";

    // Lógica de direcionamento
    if (valorY > LIMITE_ALTO) {
      comandoAtual = "Frente";
    } else if (valorY < LIMITE_BAIXO) {
      comandoAtual = "Tras";
    } else if (valorX < LIMITE_BAIXO) {
      comandoAtual = "Esquerda";
    } else if (valorX > LIMITE_ALTO) {
      comandoAtual = "Direita";
    }

    // Exibe no Monitor Serial apenas quando houver alteração de movimento
    if (comandoAtual != ultimoComando) {
      Serial.print("Comando: ");
      Serial.println(comandoAtual);
      ultimoComando = comandoAtual;
    }
  }

  delay(100);
}