#include <math.h>
int greenLedPin = 6;
int yellowLedPin = 4;
int redLedPin = 3;
int blueLedPin = 5;
int whiteLedPin = 10;
int beep = 9;
int button = 2;
int heet = 11;

int lightSensorPin = A0;
double analogValue = 0;
int buttonState = 0;
int buttLast = 0;

void setup() {
  Serial.begin(9600);
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin,OUTPUT);
  pinMode(redLedPin,OUTPUT);
  pinMode(blueLedPin,OUTPUT);
  pinMode(whiteLedPin,OUTPUT);
  pinMode(button,INPUT);
   pinMode(heet,OUTPUT);
}

double Termistor(int analogOkuma){

 double sicaklik;
 sicaklik = log(((10240000 / analogOkuma) - 10000));
 sicaklik = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * sicaklik * sicaklik)) * sicaklik);
 sicaklik = sicaklik - 273.15;
 return sicaklik;
}

void loop()
{

int deger = analogRead(A2);
  double sicaklik = Termistor(deger);
  Serial.println(sicaklik);

  if(sicaklik < 22)
  {
  	digitalWrite(heet, HIGH);
  }
  else if(sicaklik > 22)
  {
  	digitalWrite(heet, LOW);
  }

  analogValue = analogRead(lightSensorPin);
  //Serial.println(analogValue);
  if(analogValue < 30){            
    digitalWrite(redLedPin, HIGH);
    buttLast = 0;
  }
  else if(analogValue >= 30 && analogValue <= 100){
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(redLedPin, HIGH);
  }
  else if(analogValue >= 100 && analogValue <= 200){
    digitalWrite(blueLedPin, HIGH);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(redLedPin, HIGH);
  }
  else if(analogValue >= 200 && analogValue <= 300){
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(blueLedPin, HIGH);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(redLedPin, HIGH);
  }
  else{
    digitalWrite(whiteLedPin, HIGH);
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(blueLedPin, HIGH);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(redLedPin, HIGH);
  
    while(buttLast == 0)
    {
      tone(9,2000);
      delay(100);
      noTone(9);
      delay(100);

      buttonState = digitalRead(button);
      if(buttonState == 1)
      {
        buttLast = 1;
      }
  
       // Serial.println(buttLast);
      if (buttLast == 1)
      {
        noTone(9);
      }
    }
    
  }

 

//Serial.println(buttonState);
  
  delay(200);
  digitalWrite(greenLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(redLedPin, LOW);
  digitalWrite(blueLedPin, LOW);
  digitalWrite(whiteLedPin, LOW);

}