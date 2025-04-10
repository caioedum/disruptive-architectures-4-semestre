// Módulo: DOIT ESP32 DEVKIT V1
// Porta: COM5 (USB)

// Bibliotecas já instaladas na IDE:
#include <WiFi.h>
#include <HTTPClient.h>

// Bibliotecas a instalar:
#include <Arduino_JSON.h>

// Credenciais da rede WiFi
const char* ssid = "iPhone de Caio";
const char* password = "CaioForSure!";

// Chave da API Open Weather
String apiKey = "15b92776d987db0285067a75c8c666fd";

// Dados do timer
unsigned long lastTime = 0;
unsigned long timerDelay = 10000;

/*******************************************************************************

                        NÃO ALTERE O CÓDIGO A PARTIR DAQUI...

********************************************************************************/

// Variável que recebe a string JSON
String jsonBuffer;

void setup() {
  // Habilita o monitor serial:
  Serial.begin(115200);

  // Inicializa a conexão WiFi:
  WiFi.begin(ssid, password);
  Serial.println("Conectando...");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Confirma a conexão:
  Serial.println("");
  Serial.print("Conectado à rede WiFi no endereço IP: ");
  Serial.println(WiFi.localIP());
 
  // Serial.println("Timer programado para 10 segundos. Aguarde esse tempo para a leitura...");
}

void loop() {
  if ((millis() - lastTime) > timerDelay) { // Verifica o timer de 10 segundos.
    // Verifica o status da conexão WiFi
    if(WiFi.status()== WL_CONNECTED){
      
      String serverPath = "http://api.openweathermap.org/data/2.5/weather?q=S%C3%A3o%20Paulo,BR&APPID=" + apiKey;

      // Extraindo as informações da string JSON:
      jsonBuffer = httpGETRequest(serverPath.c_str());
      // Serial.println(jsonBuffer);
      JSONVar myObject = JSON.parse(jsonBuffer);
  
      // JSON.typeof(jsonVar) pode ser usado para obter o tipo da variável
      if (JSON.typeof(myObject) == "undefined") {
        Serial.println("Falha no formato dos dados!");
        return;
      }     

      // Retorna a string JSON obtida e
      // os valores de temperatura, pressão, umidade e velocidade do vento:
      Serial.println("========================================================================");
      Serial.print("JSON object = ");
      Serial.println(myObject);
      Serial.println("========================================================================");

      // Temperatura:
      Serial.print("Temperatura: ");
      Serial.print(myObject["main"]["temp"]);
      Serial.println(" K");

      // Pressão atmosférica:
      Serial.print("Pressão: ");
      Serial.print(myObject["main"]["pressure"]);
      Serial.println(" hPa");

      // Umidade:
      Serial.print("Umidade: ");
      Serial.print(myObject["main"]["humidity"]);
      Serial.println(" %");

      // Velocidade do vento:
      Serial.print("Velocidade do vento: ");
      Serial.print(myObject["wind"]["speed"]);
      Serial.println(" m/s");
      Serial.println("========================================================================");
    }
    else {
      Serial.println("WiFi desconectado");
    }
    lastTime = millis(); // Reinicia o timer...
  }
}

String httpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;
    
  // Dados do servidor
  http.begin(client, serverName);
  
  // Envia a requisição GET
  int httpResponseCode = http.GET();
  
  String payload = "{}"; 
  
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Código de erro: ");
    Serial.println(httpResponseCode);
  }
  
  http.end();

  return payload;
}