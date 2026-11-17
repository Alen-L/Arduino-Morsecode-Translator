// C++ code
//
void setup()
{
  pinMode(8, OUTPUT);
    
}

void punkt()
{
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(8, LOW);
}

void strich()
{
  digitalWrite(8, HIGH);
  delay(300);
  digitalWrite(8,LOW);
}
  
void loop()
{
  for (int i=0; i<3; i++)
  {
    punkt();
    
    if (i < 2)
    {
      delay(100);
    }
    
  }
  
  delay(300);
    
  for (int i=0; i<3; i++)
  {
    strich();
    
    if(i<2)
    {
      delay(100);
    }
  }
  
  delay(300);
  
  for (int i=0; i<3; i++)
  {
    punkt();
    
    if (i < 2)
    {
      delay(100);
    }
  }
  delay(700);
}
