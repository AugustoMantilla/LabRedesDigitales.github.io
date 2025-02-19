#define led 23               
#define PIR 33             

int pirState = LOW;           
int val = 0;                

void setup() {
    pinMode(led, OUTPUT);   
    pinMode(PIR, INPUT);   
    Serial.begin(115200);
}

void loop() {
    val = digitalRead(PIR);  
    if (val == HIGH) {            
        digitalWrite(led, HIGH); 
        if (pirState == LOW) {
            Serial.println("Motion detected!");
            pirState = HIGH;
        }
    } else {
        digitalWrite(led, LOW); 
        if (pirState == HIGH) {
            Serial.println("Motion ended!");
            pirState = LOW;
        }
    }
}
