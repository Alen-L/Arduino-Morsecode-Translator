// C++ code
//

char buchstaben[] = {'A','B','C','D','E','F'};  // Alphabet-Array
String morse[] = {".-","-...","-.-.", "-..", ".", "..-."};  //Morse-Zeichen-Array



void setup()
{
  pinMode(8, OUTPUT);
  Serial.begin(9600);  //legt die Übertragungsgeschwindigkeit in Baud fest (Bits pro Sekunde)
   
  String eingabe = "AB CD";
  
  
  int zaehler = 0;
  
  //Sucht den Buchstaben
  while (zaehler < eingabe.length())
  {
    int position = -1;  //setzt position auf nicht vorhandene Index-Position um später bei Nicht-Treffer Fehlermeldung ausgeben zu können
    char gesucht = eingabe[zaehler];  //gesuchter Buchstabe
    for (int i=0; i < 6; i++)  //erstellt Variable i, durchläuft Positionen 0 - 5 bis i = 6 erreicht ist, erhöht i bei jedem Durchlauf
    {
      if (buchstaben[i] == gesucht)  // bestimmt durchzulaufende Liste und vergleicht Buchstaben von aktueller Position mit gesuchtem Buchstaben
      {
        position = i;  //Verändert Variable position mit der aktuellen Position i
        break;  //beendet die for-Schleife bei Treffer
      }
    }

    if (position != -1)
    { //Verarbeitet Morsezeichen
      for (int i=0; i < morse[position].length(); i++)  //morse[position].length()bestimmt wie viele Morsezeichen durchlaufen werden müssen
      {
        if (morse[position][i] == '.') 
        {
          punkt();  //Führt Funktion punkt() aus wenn '.' 

        }

        else if (morse[position][i] == '-')
        {
          strich();  //führt Funktion strich() aus wenn '-'

        }
        if (i< morse[position].length()-1)
        {
          delay(100);  //macht eine Pause von 100ms zwischen jedem Zeichen de Strings außer beim letzten Zeichen 
        }

      }
    }
    else if (gesucht == ' ')
    {
      delay(400);
    }
    
    else
    {
      Serial.println("Buchstabe nicht gefunden!");  //Gibt Fehlermeldung, falls postion -1 bleibt
    }
    zaehler = zaehler +1;
    
    if (zaehler < eingabe.length())
        {
          delay(300);
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
  

void loop()
{
}
