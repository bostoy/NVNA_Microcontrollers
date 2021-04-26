#define BUTTON_PIN  2    
#define LED_PIN 10  
#define DATA_RATE 9600
#define THRESHOLD 1000
bool ledState = 0;        
bool buttonState =0;            
bool lastButtonState = 0;   
bool flag = 0;


#define BUTTON_PIN  2    
#define LED_PIN 10  
#define DATA_RATE 9600
#define THRESHOLD 1000
bool ledState = false;        
bool buttonState =0;            
bool lastButtonState = 0;   
bool flag = 0;
int count = 0;


unsigned long Time = 0;
unsigned long blinkingTime= 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(DATA_RATE);
  Serial.println("Serial interface was configured.");
 
}
void loop() {
  // read the state of the switch into a local variable:
buttonState = digitalRead(BUTTON_PIN);

  
  if (buttonState){
    if(lastButtonState != buttonState){
   	Time = millis();
      lastButtonState = buttonState;
    }
      if(millis() - blinkingTime >500){
        toggleLed();
        blinkingTime = millis();
        count++;
      }

  }else{
      if(lastButtonState !=buttonState){
      Serial.println("Time of Blinking");
      Serial.println(millis()-Time);
      Serial.println("Count: ");
      Serial.println(count);
      lastButtonState = buttonState;
        count= 0;
      }
  }
  


}
                 void toggleLed(){
                     ledState = !ledState;
                   	digitalWrite(LED_PIN,ledState);
                     }
                     
void LedOn(){
  digitalWrite(LED_PIN, HIGH);
  ledState = HIGH;
}
void LedOff(){
  digitalWrite(LED_PIN, LOW);
   ledState = LOW;
}

  /*  if(buttonState){
      
     if(!flag){
      Time=millis();
       flag = !flag;
      }
    
    }else {
       if(flag){
       Serial.println((millis() - Time));
       
        
       if(ledState){
      	if((millis() -Time)> 2000){
      		LedOff();
      	}
    }else {
      if((millis() - Time )> 1000){
        LedOn();
      }
    }
        flag=!flag;
  }
}*/