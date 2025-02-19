int led=23;
int button=34;
int buttonState=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(23,OUTPUT);
  pinMode(34,INPUT);
}

void loop() {
  
  buttonState=digitalRead(button);

  if(buttonState==1){
    digitalWrite(led,HIGH);
  }
  if (buttonState==0){
    digitalWrite(led,LOW);
  }

}
