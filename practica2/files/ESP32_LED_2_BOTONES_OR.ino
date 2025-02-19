int led=23;
int button_1=34;
int button_2=35;
int buttonState_1=0;
int buttonState_2=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(button_1,INPUT);
  pinMode(button_2,INPUT);
}

void loop() {
  buttonState_1=digitalRead(button_1);
  buttonState_2=digitalRead(button_2);
  if((buttonState_1==1) || (buttonState_2==1)){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
}
