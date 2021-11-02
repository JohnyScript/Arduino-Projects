int val = 0;

int currentMillis = 0;

void setup()
{
  pinMode(A5, INPUT);
  
  Serial.begin(9600);
}


void loop()
{
  if((millis() / 1000) <= currentMillis)
  {
    return;
  }
  
  currentMillis = (millis() / 1000);
  val = analogRead(A5);
  Serial.println(val);
  
}
