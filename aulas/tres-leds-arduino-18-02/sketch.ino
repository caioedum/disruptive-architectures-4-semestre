/*
Exemplo 1:
Os três LEDs deverão piscar simultaneamente em intervalos de 300ms.

Exemplo 2:
Os LEDs vermelho e verde deverão psicar alternadamente
em intervalos de 400ms.

Exemplo 3:
Crie um código para simular um semáforo
Verde ---> 4 segundos
Amarelo ---> 1 segundo
Vermelho ---> 6 segundos
*/

// Atribui nomes aos pinos
#define ledRED 3
#define ledYEL 7
#define ledGRE 12

void setup() {
  // put your setup code here, to run once:
  // Configura os pinos dos LEDs como saída
  // (OUTPUT)
  pinMode(ledRED, OUTPUT);
  pinMode(ledYEL, OUTPUT);
  pinMode(ledGRE, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  ex1();
}

void ex1() {
/*
Exemplo 1:
Os três LEDs deverão piscar simultaneamente em intervalos de 300ms.
*/
digitalWrite(ledRED, HIGH);
digitalWrite(ledYEL, HIGH);
digitalWrite(ledGRE, HIGH);
delay(300);
digitalWrite(ledRED, LOW);
digitalWrite(ledYEL, LOW);
digitalWrite(ledGRE, LOW);
delay(300);
}

