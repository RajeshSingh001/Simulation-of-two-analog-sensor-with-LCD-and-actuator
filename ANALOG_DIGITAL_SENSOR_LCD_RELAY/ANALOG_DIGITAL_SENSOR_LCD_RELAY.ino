#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{  
  lcd.begin(16, 2);
  Serial.begin(9600);
  //start serial connection
  //configure pin2 as an input and enable the internal pull-up resistor
  pinMode(10, INPUT_PULLUP);
  pinMode(9, OUTPUT);
   //lcd.setCursor(0, 0);
   lcd.print("ANALOG+DIGITAL");
   lcd.setCursor(0, 1);
   lcd.print("SENSOR SYSTEM");
   delay(1000);
   lcd.clear();
}

void loop() 
{
  //read the pushbutton value into a variable
   int sensorValue1 = analogRead(A0);
   int sensorValue2 = digitalRead(10);
   int TEMP1=sensorValue1/2;
  
    //print out the value of the pushbutton
   lcd.setCursor(0, 0);
   lcd.print("SENSOR1:");
   lcd.print(TEMP1);
   if (sensorValue2 == LOW)
  {
    digitalWrite(12, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("SENSOR2:");
    lcd.print(sensorValue2);
  } 
  else 
  {
    digitalWrite(12, LOW);
    lcd.setCursor(0, 1);
    lcd.print("SENSOR2:");
    lcd.print(sensorValue2);
  }
  
   
   Serial.print("SENSOR1:");
   Serial.print(TEMP1);
   Serial.print("SENSOR2:");
   Serial.print(sensorValue2);
   delay(500);
      
 /* if (TEMP >=50)
  { 
    lcd.clear();
    digitalWrite(9, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("OVER TEMP");
    delay(20);
  } 
  else 
  { 
    lcd.clear();
    digitalWrite(9, LOW);
    lcd.setCursor(0, 1);
    lcd.print("NORMAL TEMP ");
    delay(20);
  }*/
  
}
