#define pinRed 13
#define onTime 400
#define offTime 1250

void setup(){
  pinMode(pinRed, OUTPUT);
}

void loop()
{
  redLedOn();
  delay(onTime);
  
  redLedOff();
  delay(offTime);
}

void redLedOn (){
  digitalWrite(pinRed, HIGH);
}
void redLedOff (){
    digitalWrite(pinRed, LOW);
}