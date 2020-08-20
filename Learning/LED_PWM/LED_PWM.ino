#include <Keyboard.h>

int ledpin = 6;
int ledbrightness = 0;
void setup() {
  pinMode(ledpin,OUTPUT);
}

void loop()
{
  
  ledbrightness = ledbrightness + 5;
  analogWrite(ledpin,ledbrightness);
  delay(100);
 
}
