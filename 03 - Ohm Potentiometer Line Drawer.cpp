#include <LiquidCrystal.h>

// Setup the LCD screen
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Potentiometer Data
int potentiometerValue = 0;
int currentLCDNode = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(A5, INPUT);
  
  lcd.begin(16, 2);
}


void loop()
{
  if(analogRead(A5) == potentiometerValue)
  {
    return;
  }
  potentiometerValue = analogRead(A5);
  currentLCDNode = potentiometerValue / 32;
  
  lcd.clear();
  LCDDrawerLineZero();
}

// Draws lines on each Pixel group of the LCD
void LCDDrawerLineZero()
{
  lcd.setCursor(0, 0);
  
  for(int i = 1; i <= currentLCDNode; i++)
  {
    if(i > 16)
      break;
    
    lcd.print('-');
  }
  
  if(currentLCDNode >= 16)
    LCDDrawerLineOne();
}

void LCDDrawerLineOne()
{
  lcd.setCursor(0, 1);
  
  for(int i = 1; i <= (currentLCDNode - 16) + 1; i++)
  {    
    lcd.print('-');
  }
}
