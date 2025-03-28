#include "WiFi.h"

void setup() {
  Serial.begin(115200);
  Serial.println("Inicializando WiFi...");
  
  WiFi.mode(WIFI_STA);
  Serial.println("Configuración terminada!");
}

void loop() {
  Serial.println("Escaneando...");
  
  int n = WiFi.scanNetworks();
  Serial.println("Escaneo terminado!");
  
  if (n == 0) {
    Serial.println("No se encontraron redes.");
  } else {
    Serial.println();
    Serial.print(n);
    Serial.println(" redes encontradas");
    
    for (int i = 0; i < n; ++i) {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
      
      delay(10);
    }
  }
  Serial.println("");
  delay(5000);
}