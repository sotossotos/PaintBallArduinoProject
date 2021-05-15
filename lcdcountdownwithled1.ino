#include <LiquidCrystal.h>
#include <stdlib.h>
#include <string.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
bool trigger=false;
int INTERVAL=100;
int timer_display=7;
bool pause_countdown=false;
int ledPin=13;
int buttonPin=7;
int pressed=0;
int t=INTERVAL;
void setup() {
  lcd.begin(16, 2);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT); 
  lcd.print("Time Remaining");
  lcd.setCursor(timer_display,1);
  digitalWrite(ledPin,HIGH);
  lcd.print(t); 
}
void loop() {
	pressed=digitalRead(buttonPin);
  if (pressed==HIGH){
      digitalWrite(ledPin,HIGH);
      lcd.setCursor(timer_display, 1);
      if(t>0)
      {
        t--;
      }else
      {
        t=INTERVAL;
      }
      if(pause_countdown)
      {
        t=INTERVAL;
        lcd.setCursor(timer_display,1);
        lcd.print(t);
      }
      else
      {
        delay(1000);
        if (t>=100){
          lcd.setCursor(timer_display,1);
        }else if (t>=10)
        {
          lcd.setCursor(timer_display,1);
          lcd.print('0');
          lcd.setCursor((timer_display+1),1);
        }else
        {
         lcd.setCursor((timer_display+1),1);
         lcd.print('0');
         lcd.setCursor((timer_display+2),1);
        }
        lcd.print(t);
      }
      if(t==0)
      {
        pause_countdown=true;
        trigger=true;
      }
      if (trigger)
      {
        //digitalWrite(ledPin,HIGH);
        digitalWrite(ledPin,LOW);
        delay(3000);
        pause_countdown=false;
        
        trigger=false;
      }
  }else{t=INTERVAL;lcd.setCursor(timer_display,1);lcd.print(t);}
}
 