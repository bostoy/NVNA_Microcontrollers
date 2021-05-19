#define diodeRed 12
#define buttonPin 2
#define twoClicks 2
#define threeClicks 3
#define bitRate 9600

bool diodeState = 0;
bool buttonState = 0;
bool prevDiodeState = 0;
int count=0;
int incomingByte = 0; 

void setup()
{
  pinMode(buttonPin, INPUT);
  pinMode(diodeRed, OUTPUT);
  Serial.begin(bitRate);
  Serial.println("Serial was configured");
  Serial.println("1,2 ili 3 izberi");
  while (Serial.available()== 0);
    // read the incoming byte:
    incomingByte = Serial.parseInt();
    Serial.println(incomingByte);
}

void loop()
{
  // read the state of the pushbutton value
  buttonOnOff();
  
  buttonState = digitalRead(buttonPin);
  // check if pushbutton is pressed.  if it is, the
  // buttonState is HIGH
  /* if (buttonOnOff()) {
    // turn LED on
    diodeRedOn();
  } else {
    // turn LED off
    diodeRedOff();
  }*/
 /*
  if (buttonOnOff()== HIGH)
  {
    count++;
    if(diodeState){
      if(count == twoClicks){
      toggleOnOff();
        count=0;
      }
    }else{
      if(count == threeClicks){
      toggleOnOff();
        count=0;
      }
    }
  }
 */
  
  switch (incomingByte) {
  case 1:
    //do something when var equals 1
    clickButton(buttonState);
    break;
  case 2:
    //do something when var equals 2
    holdButton(buttonState);
    break;
    case 3:
    //do something when var equals 2
    buttonWithLogic(buttonState);
    break;
  default:
    // if nothing else matches, do the default
    // default is optional
    Serial.println("Greshen izbor");
    break;
}
  
  //clickButton(buttonState);
   // holdButton(buttonState);
  //buttonWithLogic(buttonState);
  
  delay(100); // Delay a little bit to improve simulation performance
}

void clickButton(bool buttonState){
  if(buttonState){
   toggleOnOff();
    Serial.println("Toggle Led");
  }
}
  
  void holdButton(bool buttonState){
    int flag=0;
    if(buttonState){
    diodeRedOn();     
      if(diodeState != prevDiodeState)
      {
      Serial.println("LED is on");
     prevDiodeState=diodeState;
       }
    }else{
    diodeRedOff();
      if(diodeState != prevDiodeState)
      {
      Serial.println("LED is off");
       prevDiodeState=diodeState;
       }
      }
    }
  
  
  void buttonWithLogic(bool buttonState){
    if(buttonState){
    count++;
      Serial.println(count);
      if(diodeState){
        if(count == threeClicks){
        diodeRedOff();
          Serial.println("LED is off");
          count =0;
        }
      }else{
        if(count == twoClicks){
         diodeRedOn();
          Serial.println("LED is on");
          count=0;
        }
      }
    }
  }

bool buttonOnOff(){
 return digitalRead(buttonPin);
}

void diodeRedOn(){
  diodeState = HIGH;
  digitalWrite(diodeRed, diodeState);
}

void diodeRedOff(){
  diodeState = LOW;
  digitalWrite(diodeRed, diodeState);
}

void toggleOnOff(){
 diodeState = !diodeState;
  digitalWrite(diodeRed, diodeState);
}
