#define LED_PIN 10
#define ANALOG_PIN A0
#define BIT_RATE 9600
#define SENSITIVITY_THRESHOLD 327
int sensorValue = 0;
int previousValue= 0;
int minValue = 1023;
int maxValue = 0;
int lastChange = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(BIT_RATE);
  Serial.println("Serial was configured");
}

void loop()
{
 
  sensorValue = analogRead(ANALOG_PIN);
  
  if(sensorValue >= SENSITIVITY_THRESHOLD){
   	LedOn();
 
  }else{
        LedOff();
  }
  displayState(sensorValue);
 
}
void LedOn(){
  digitalWrite(LED_PIN, HIGH);
  delay(sensorValue);
}
void LedOff(){
 digitalWrite(LED_PIN, LOW);
  delay(sensorValue); 
}

void displayState(int currentValue){
 
  float resistance = 0;
  /* if(previousValue >= currentValue) {
    
  	lastChange = previousValue - currentValue;
  }else{
    lastChange = currentValue-previousvalue;
  }; */
  
  
  if(previousValue != currentValue){
    previousValue = currentValue;
      resistance =  convertResistance(currentValue);
      Serial.println(resistance);
      Serial.println(previousValue);
  }
     if(previousValue <= minValue){
      minValue = previousValue;
    }
    
    if(previousValue >= maxValue){
      maxValue = previousValue;                         
    }
  
}

float convertResistance(int value){
return float(value*5)/1023;
}