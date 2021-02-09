#define pinRed 13
#define pinBlue 4
#define onTime 1000
#define offTime 1000

int counter= 0;

void setup(){
  pinMode(pinRed, OUTPUT);
  pinMode(pinBlue,OUTPUT);
}

void loop()
{
 if(counter < 2){
  tact();
 }else if(counter < 4){
   reversed();
   if(counter == 3){
      counter =0;
     return;
   }
  
 }
  
 counter++;
};

void tact(){
   ledOn(pinRed);
   ledOn(pinBlue);
   delay(onTime);
  

  ledOff(pinBlue);
  ledOff(pinRed);
  delay(offTime);
}
void reversed(){
   ledOn(pinRed);
  delay(onTime);
  
  ledOn(pinBlue);
  ledOff(pinRed);
  delay(offTime);
  ledOff(pinBlue);
}

void ledOn (int pin){
  digitalWrite(pin, HIGH);
}
void ledOff (int pin){
    digitalWrite(pin, LOW);
}