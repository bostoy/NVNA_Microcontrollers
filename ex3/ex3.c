#define ledPin 13
#define buttonPin 2
bool buttonState;
bool ledState;

void setup()
{
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
 //switchLedFirstPart(ledPin);
  
 switchLed(ledPin);
}

void switchLedFirstPart(int pin){
  buttonState = digitalRead(buttonPin);

  if(buttonState){
    ledOn(pin);
    delay(100);
  }else{
    ledOff(pin);
	delay(100);
}
};


void switchLed(int pin){  
buttonState = digitalRead(buttonPin);

  if(buttonState){
    if(ledState){
      ledOff(ledPin);
      ledState = false;
      delay(100);
    }else{
      ledOn(ledPin);
      ledState = true;
      delay(100);
    }
  }
}

void ledOn (int pin){
  digitalWrite(pin, HIGH);
}
void ledOff (int pin){
  digitalWrite(pin, LOW);
}