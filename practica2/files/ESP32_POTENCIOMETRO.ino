int led=23;
int pot=34;

int potValue=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(23,OUTPUT);
  pinMode(34,INPUT);
}

void loop() {
  
  potValue=analogRead(pot);

  if(potValue>=1024){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }

}
