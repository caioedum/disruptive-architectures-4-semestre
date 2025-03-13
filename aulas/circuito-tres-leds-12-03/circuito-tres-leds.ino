// Atribui nomes aos pinos de I/O
#define BT1 8
#define BT2 9
#define ledR 2
#define ledW 3
#define ledB 4

bool statusBT1;
int contador;

void setup() {
  // Habilitar comunicação serial (baud rate de 9600 bits/s)
  Serial.begin(9600);  
  // Configurar os pinos de I/O:
  pinMode(BT1, INPUT);
  pinMode(BT2, INPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledW, OUTPUT);
  pinMode(ledB, OUTPUT);

  for(int i = 0; i < 10; i++){
    Serial.println(i);
    piscaW();
  }

  Serial.println("Fim da inicialização");
  delay(2000);
}

void loop() {
    piscaRB();     
}

void piscaRB(){
    digitalWrite(ledB, HIGH);
    digitalWrite(ledR, LOW);
    delay(250);
    digitalWrite(ledR, HIGH);
    digitalWrite(ledB, LOW);
    delay(250);
}

void piscaW(){
    digitalWrite(ledR, LOW);
    digitalWrite(ledW, HIGH);
    delay(300);
    digitalWrite(ledW, LOW);
    delay(300);    
}








