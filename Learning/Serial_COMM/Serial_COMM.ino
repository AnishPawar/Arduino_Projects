int ledpin = 13;
int val = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available() == 0);
  
  val = Serial.read() - '0';
  Serial.println(val)
  
  if(val == 0)
  {
  digitalWrite(ledpin,LOW);
  Serial.println("Off");
  }
  else if(val == 1)
  {digitalWrite(ledpin,HIGH);
  Serial.println("On");
  }
  Serial.flush();
}
