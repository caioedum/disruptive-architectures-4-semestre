/*
Linguagem Wiring (C++ adaptado para uC)

Pinos de entrada / saída
Input / Output (I/Os)
(pinos de 0 a 13)
Digitais:

INPUT ----> botão, sensor digital...

OUTPUT -----> LED, relé, pequeno motor, buzzer...

0 Volt ----> 0, false ou LOW
5 Volts ----> 1, true ou HIGH

Pino Output ----> 5 Volts
LED ----> 2 Volts
Resistor ----> 3 Volts

Frequência de clock ---> 16 MHz
Ciclo de instrução ----> T

T = 1 / 16000000
T = 0.0000000625
T = 62.5 ns

Variável -----> 2^8 = 256 (0 a 255)

2^16 = 65.536 (0 a 65.535)

-32768 a +32767
*/

//Atribuir um nome ao pino
#define LED 8
// const int LED = 8;
// int LED = 8; 

void setup() {
  // put your setup code here, to run once:
  // Configura o pino do LED como OUTPUT
  pinMode(LED, OUTPUT);


}

/*
Piscar o LED em intervalos de meio segundo
0.5s = 500ms
*/
void loop() {
  // put your main code here, to run repeatedly:
  // Liga o LED
  digitalWrite(LED, HIGH);
  // Aguarda 500ms
  delay(500);
  // Desliga o LED
  digitalWrite(LED, LOW);
  // Aguarda 500ms
  delay(500);
}
