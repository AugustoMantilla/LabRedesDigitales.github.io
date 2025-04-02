#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

// Puertos GPIO
int boton = 4;
int led = 5;
int potenciometro = 6; // GPIO para el potenciómetro
int pir = 7; // GPIO para el sensor PIR
DHT dht(0, DHT22);

// Variables status
int status_boton = 0;
int valor_potenciometro = 0;
int status_pir = 0;
int valor_temperatura = 0;

// PHP server
String url = "https://api.thingspeak.com/update?";
String api_key = "NZUJ6QMBRY8VJSTS";
String sensordht = "field5";
String url_boton = "https://58632bcd-835e-42f9-9ecc-644a33682562-00-1229jg7ktjbyb.janeway.replit.dev/sensor1/?";
String url_potenciometro = "https://58632bcd-835e-42f9-9ecc-644a33682562-00-1229jg7ktjbyb.janeway.replit.dev/sensor2/?";
String url_pir = "https://58632bcd-835e-42f9-9ecc-644a33682562-00-1229jg7ktjbyb.janeway.replit.dev/sensor3/?";
String sensor = "DATO";

void setup() {
    // Configuración de pines
    pinMode(boton, INPUT);
    pinMode(led, OUTPUT);
    pinMode(potenciometro, INPUT);
    pinMode(pir, INPUT);
    dht.begin();

    delay(1000);
    Serial.begin(115200);
    
    WiFi.begin("Guty", "123456789"); // WiFi_Network, WiFi_Password

    // Wait until connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("WiFi connected");
}

void loop(){
    status_boton = digitalRead(boton);
    valor_potenciometro = analogRead(potenciometro); // Leer el valor del potenciómetro
    status_pir = digitalRead(pir); // Leer el estado del sensor PIR
    valor_temperatura = dht.readTemperature();

    if(status_boton == 1){
        digitalWrite(led, HIGH);
    } else {
        digitalWrite(led, LOW);
    }

    // Wait for WiFi connection
    if(WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        
        // Enviar estado del botón
        String message_boton = url_boton + sensor + "=" + String(status_boton);
        http.begin(message_boton);
        int httpCode_boton = http.GET();
        Serial.println(message_boton);
        Serial.print("GET code (boton): ");
        Serial.println(httpCode_boton);
        http.end();
        
        // Enviar valor del potenciómetro
        String message_potenciometro = url_potenciometro + sensor + "=" + String(valor_potenciometro);
        http.begin(message_potenciometro);
        int httpCode_potenciometro = http.GET();
        Serial.println(message_potenciometro);
        Serial.print("GET code (potenciómetro): ");
        Serial.println(httpCode_potenciometro);
        http.end();
        
        // Enviar estado del sensor PIR
        String message_pir = url_pir + sensor + "=" + String(status_pir);
        http.begin(message_pir);
        int httpCode_pir = http.GET();
        Serial.println(message_pir);
        Serial.print("GET code (PIR): ");
        Serial.println(httpCode_pir);
        http.end();

        String message = url + "api_key=" + api_key + "&" + sensordht + "=" + String(valor_temperatura);
        http.begin(message);
        int httpCode = http.GET();
        Serial.println(message);
        Serial.print("Código GET: ");
        Serial.println(httpCode);
        http.end();
    }
    
    delay(3000);
}
