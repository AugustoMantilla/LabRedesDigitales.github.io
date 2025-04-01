#include <DHT.h>
#include <WiFi.h>
#include <HTTPClient.h>

int led = 4;
DHT dht(5, DHT22);

int valor_temperatura = 0;
int valor_humedad = 0;

String url = "https://api.thingspeak.com/update?";
String api_key = "NZUJ6QMBRY8VJSTS";
String sensor = "field5";

void setup() {
  pinMode(led, OUTPUT);
  dht.begin();
  
  delay(1000);
  Serial.begin(115200);
    
  WiFi.begin("Guty", "123456789");

  while ((WiFi.status() != WL_CONNECTED)) {
    delay(500);
    Serial.print(".");
  }   
  Serial.println("WiFi conectado");
}

void loop() {
  delay(1000);

  valor_temperatura = dht.readTemperature();
  valor_humedad = dht.readHumidity();

  Serial.print("Temperatura: ");
  Serial.println(valor_temperatura);
  Serial.print("Humedad: ");
  Serial.println(valor_humedad);

  if (valor_humedad >= 50) { 
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }

  if ((WiFi.status() == WL_CONNECTED)) {
    HTTPClient http;
    String message = url + "api_key=" + api_key + "&" + sensor + "=" + String(valor_humedad);
    http.begin(message);
    int httpCode = http.GET();
    Serial.println(message);
    Serial.print("Código GET: ");
    Serial.println(httpCode);
    http.end();
  }

  delay(1000);
}
