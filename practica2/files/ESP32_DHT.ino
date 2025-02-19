int led=23;
int temperatura=0;
int humedad=0;
#include <DHT.h>

DHT dht(33,DHT22);

void setup() {
  // put your setup code here, to run once:
  pinMode(23,OUTPUT);
  dht.begin();
  Serial.begin(115200);
}

void loop() {
  
  delay(1000);
  temperatura=dht.readTemperature();
  humedad=dht.readHumidity();

  Serial.print("Temperatura:");
  Serial.println(temperatura);
  Serial.print("Humedad:");
  Serial.println(humedad);


  if(humedad>=50){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }

}
