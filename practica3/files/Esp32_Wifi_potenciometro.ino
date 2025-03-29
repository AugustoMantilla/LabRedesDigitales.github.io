#include <WiFi.h>
#include <HTTPClient.h>
 
int led=1;
 
int pot=4;
int potValue=0;
 
String url="https://api.thingspeak.com/update?";
String api_key="NZUJ6QMBRY8VJSTS";
String sensor="field2";
 
void setup() {
  // put your setup code here, to run once:
  pinMode(1,OUTPUT);
  delay(1000);
  Serial.begin(115200);
  WiFi.begin("Guty", "123456789");
 
  while((WiFi.status() != WL_CONNECTED)){
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi Connected");
 
}
 
void loop() {
 
  potValue=analogRead(pot);
 
  if(potValue>=1024){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
  if((WiFi.status()== WL_CONNECTED)){
 
    HTTPClient http;
    String message=url+"api_key="+api_key+"&"+sensor+"="+String(potValue);
    http.begin(message);
 
    int httpCode = http.GET();
    Serial.println(message);
    Serial.print("GET code:");
    Serial.println(httpCode);
    http.end();
  }
  delay(1000);
 
}