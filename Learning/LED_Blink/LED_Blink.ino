int led = 9;
int counter = 0;

void setup() 
{
  pinMode(led,OUTPUT);
}

void loop() {
 

  if (counter<10)
  {
  digitalWrite(led,HIGH);
  delay(100);
  digitalWrite(led,LOW);
  delay(100);
  }
  else
  {
  digitalWrite(led,HIGH);
  delay(1000);
  digitalWrite(led,LOW);
  delay(1000);
  }
  counter++;
}
