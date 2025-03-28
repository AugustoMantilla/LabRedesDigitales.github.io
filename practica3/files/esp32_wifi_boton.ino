#include <WiFi.h>
#include <HTTPClient.h>

int boton = 4;
int led = 1;

int status_boton = 0;

String url = "https://api.thingspeak.com/update?";
String api_key = "NZUJ6QMBRY8VJSTS";
String sensor = "field1";

void setup() {
  pinMode(led, OUTPUT);
  pinMode(boton, INPUT);

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
  status_boton = digitalRead(boton);

  if (status_boton == 1) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }

  if ((WiFi.status() == WL_CONNECTED)) {
    HTTPClient http;

    String message = url + "api_key=" + api_key + "&" + sensor + "=" + String(status_boton);
    http.begin(message);

    int httpCode = http.GET();
    Serial.println(message);
    Serial.print("Código GET: ");
    Serial.println(httpCode);

    http.end();
  }

  delay(3000);
}
