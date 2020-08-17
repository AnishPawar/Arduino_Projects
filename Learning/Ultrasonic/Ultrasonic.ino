int trig = 10;
int echo = 9;

long duration;
float distance;

void setup() 
{
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
Serial.begin(9600);  

}

void loop() 
{
  digitalWrite(trig,LOW);
  delay(250);

  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  duration =  pulseIn(echo,HIGH);
  distance = duration*0.034/2;
  Serial.println("Distance (cm):");
  Serial.println(distance);
}
