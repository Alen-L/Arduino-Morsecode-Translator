// C++ code
//

char buchstaben[] = {'A','B','C','D','E','F'};  // Alphabet-Liste
String morse[] = {".-","-...","-.-.", "-..", ".", "..-."};  //Morse-Zeichen-Liste

void setup()
{
  pinMode(8, OUTPUT);
  
  char gesucht = 'D';  //Gesuchter Buchstabe
  int position = -1;  //setzt Position auf nicht vorhandene Index-Position um bei nicht-treffer keine falsche Ausgabe zu bekommen
  
  for (int i=0; i < 6; i++)  //Erstellt Variable i, durchläuft Liste bis Postion 6 erreicht ist, erhöht i bei jedem Durchlauf
  {
    if (buchstaben[i] == gesucht)  // sagt welche Liste und vergleicht Position mit gesuchtem Wert
    {
      position = i;  //Überschreibt i mit aktueller Position
    }
  }
    
}

void punkt() //der Punkt-Bestandteil des Buchstaben
{
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(8, LOW);
}

void strich() //Strich-Bestandteil des Buchstaben
{
  digitalWrite(8, HIGH);
  delay(300);
  digitalWrite(8,LOW);
}
  
void buchstabe_S()  //Buchstabe S
{
  for (int i=0; i<3; i++)
  {
    punkt();
    
    if (i < 2)
    {
      delay(100);
    }
   }
}
  
 
void buchstabe_O()  //Buchstabe O 
{
  for (int i=0; i<3; i++)
  {
    strich();
    
    if(i<2)
    {
      delay(100);
    }
  }
}
 


void loop()
{
}
