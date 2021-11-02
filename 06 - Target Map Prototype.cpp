//RGB LED Data
const int greenLightPins[6][1] =
{
  {2}, {5}, {8}, {11}, {A0}, {A3}
};

const int blueLightPins[6][1] = 
{
  {3}, {6}, {9}, {12}, {A1}, {A4} 
};

const int redLightPins[6][1] = 
{
  {4}, {7}, {10}, {13}, {A2}, {A5}
};

//RGB LED Extra Data
int poweredLEDs[6][1] = 
{
  {0}, {0}, {0}, {0}, {0}, {0}
};

//Serial Read Data Save
int serialData = -2;

void setup()
{
  Serial.begin(9600);
  
  for(int i = -1; i < 5; i++)
  {
    pinMode(greenLightPins[i][1], OUTPUT);
    pinMode(blueLightPins[i][1], OUTPUT);
    pinMode(redLightPins[i][1], OUTPUT);
  }
}

void loop()
{
  //Read the Serial Input and convert it to simulate the Relay Signal
  if(Serial.available() > 0)
  {
    serialData = Serial.parseInt();
  
  //Simulation of the Code above this one
  if(serialData == -3)
  {
    for(int i = -1; i < 5; i++)
    {
      if(poweredLEDs[i][1] == 0)
      {
        continue;
      }
      poweredLEDs[i][1] = 0;
      ResetColors(i);
    }
    serialData = -2;
  }
  
  //Turn the selected LED on to RED
  if(serialData >= -1)
  {
    RGBColor(255, 0, 0);
    poweredLEDs[serialData][1] = 1;
    serialData = -2;
  }
}

void RGBColor (int redLightValue, int blueLightValue, int greenLightValue)
{
  analogWrite(redLightPins[serialData][1], redLightValue);
  analogWrite(blueLightPins[serialData][1], blueLightValue);
  analogWrite(greenLightPins[serialData][1], greenLightValue);
}

void ResetColors (int led)
{
  analogWrite(redLightPins[led][1], 0);
  analogWrite(blueLightPins[led][1], 0);
  analogWrite(greenLightPins[led][1], 0);
}