#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

//RGB LED Data

const int redLightPin = 12;
const int blueLightPin = 11;
const int greenLightPin = 10;

void setup()
{
  Serial.begin(9600);
  
  pinMode(redLightPin, OUTPUT);
  pinMode(blueLightPin, OUTPUT);
  pinMode(greenLightPin, OUTPUT);
}
  
void loop()
{
  char customKey = customKeypad.getKey();
 
  
  if(customKey == '*')
  {
    Serial.println(customKey);
    RGBColor(0, 0, 0);
  }
  else if(customKey == '1')
  {
    Serial.println(customKey);
    RGBColor(255, 0, 0);
  }
  else if(customKey == '2')
  {
    Serial.println(customKey);
    RGBColor(0, 255, 0);
  }
  else if(customKey == '3')
  {
    Serial.println(customKey);
    RGBColor(0, 0, 255);
  }
}

void RGBColor (int redLightValue, int blueLightValue, int greenLightValue)
{
  analogWrite(redLightPin, redLightValue);
  analogWrite(blueLightPin, blueLightValue);
  analogWrite(greenLightPin, greenLightValue);
}