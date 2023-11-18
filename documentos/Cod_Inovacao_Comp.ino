#define BLYNK_TEMPLATE_ID "TMPL2jTF0Rq-w"
#define BLYNK_TEMPLATE_NAME "Irrigação Automatica"
#define BLYNK_AUTH_TOKEN "9eAlpggoLWLjNWWfej7OkL_-EjZWQLPd"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "iPhone";
char pass[] = "mickeli@01";

// Código de Funcionamento para Sistema de Monitoramento e Irrigação com Arduino
 
#define pinoAnalog 14 // Define o pino A0 como "pinoAnalog"
#define pinoRele 5 // Define o pino 8 como "pinoRele"
#define pino5V 3.3 // Define o pino 7 como "pino5V"
 
int ValAnalogIn; // Introduz o valor analógico ao código
 
void setup() {
Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

Serial.begin(9600); // Declara o BaundRate em 9600
pinMode(pinoRele, OUTPUT); // Declara o pinoRele como Saída
pinMode(pino5V, OUTPUT); // Declara o pino5V como Saída
digitalWrite(pino5V, HIGH); // Põem o pino5V em estado Alto = 5V
}
 
void loop() {
Blynk.run();

ValAnalogIn = analogRead(pinoAnalog); // Relaciona o valor analógico com o recebido do sensor
int Porcento = map(ValAnalogIn, 1023, 0, 0, 100); // Relaciona o valor analógico à porcentagem
 
Serial.print(Porcento); // Imprime o valor em Porcento no monitor Serial
Serial.println("%"); // Imprime o símbolo junto ao valor encontrado
Blynk.virtualWrite(V0, Porcento);

if (Porcento <= 45) { // Se a porcentagem for menor ou igual à
Serial.println("Irrigando a planta ..."); // Imprime a frase no monitor serial
digitalWrite(pinoRele, HIGH); // Altera o estado do pinoRele para nível Alto
}
 
else { // Se não ...
Serial.println("Planta Irrigada ..."); // Imprime a frase no monitor serial
digitalWrite(pinoRele, LOW); // Altera o estado do pinoRele para nível Baixo
}
delay (1000); // Estabelece o tempo de 1s para reinicializar a leitura
}
