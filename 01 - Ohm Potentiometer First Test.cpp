#include <LiquidCrystal.h>

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int currentMillis = 0;

void setup()
{
  Serial.begin(9600);
  
  lcd.begin(16, 2);
  
  lcd.print("hello, world!");
  //lcd.print("");
  lcd.blink();
}

void loop()
{
  if((millis() / 1000) <= currentMillis)
  {    
    return;
  }
  
  currentMillis = (millis() / 1000);
  
  lcd.setCursor(0, 1);
  
  lcd.print(millis()/ 1000);
}
