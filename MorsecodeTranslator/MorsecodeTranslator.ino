// C++ code
//

char buchstaben[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','1','2','3','4','5','6','7','8','9','0','.',',','?'};  // Alphabet-Array
String morse[] = {".-","-...","-.-.", "-..", ".", "..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",".----","..---","...--","....-",".....","-....","--...","---..","----.","-----",".-.-.-","--..--","..--.."};  //Morse-Zeichen-Array, gleiche Positionen wie im buchstaben[]-Array


void setup()
{
  pinMode(8, OUTPUT);   //Legt Pin 8 als Ausgang für die LED fest
  Serial.begin(9600);  //legt die Übertragungsgeschwindigkeit in Baud fest (Bits pro Sekunde)
  Serial.println("Text zum Morsen eingeben:");  //Gibt die erste Eingabeaufforderung beim Programmstart aus
   
}

//Funktionen für die Ausgabe der Morsezeichen
void punkt() //der Punkt-Bestandteil des Buchstaben
{
  digitalWrite(8, HIGH);   //Schaltet die LED ein
  delay(100);             //LED bleibt für 100ms eingeschaltet
  digitalWrite(8, LOW);  //Schaltet die LED wieder aus
}

void strich() //Strich-Bestandteil des Buchstaben
{
  digitalWrite(8, HIGH);
  delay(300);
  digitalWrite(8,LOW);
}
  
 
void loop()                                               //Wird ständig wiederholt, damit mehrere Eingaben nacheinander möglich sind
{
  
  if (Serial.available() > 0)                           //Prüft ob mindestens ein Byte über den Serial-Monitor empfangen wurde
  {
    
    String eingabe = Serial.readStringUntil('\n');   //Liest die Eingabe bis zum Zeilenumbruch ein und speichert sie als String
    eingabe.toLowerCase();                          //Wandelt alle Großbuchstaben in Kleinbuchstaben um, damit sie mit buchstaben[] verglichen werden können
  
    int zaehler = 0;                              //Zählt die Positionen der Zeichen im Eingabestring, beginnt bei Index 0

    //Durchläuft den eingegebenen Text Zeichen für Zeichen
    while (zaehler < eingabe.length())  //Wiederholt die Verarbeitung solange das Ende des Eingabestrings nicht erreicht ist

    {
      int position = -1;                            //setzt position auf nicht vorhandene Index-Position um später bei Nicht-Treffer Fehlermeldung ausgeben zu können
      char gesucht = eingabe[zaehler];             //Speichert das aktuelle Zeichen aus der Eingabe in gesucht
      for (int i=0; i < sizeof(buchstaben); i++)  //erstellt Variable i, durchläuft Positionen des Arrays, erhöht i bei jedem Durchlauf
      {
        if (buchstaben[i] == gesucht)           // bestimmt durchzulaufende Liste und vergleicht Buchstaben von aktueller Position mit gesuchtem Buchstaben
        {
          position = i;                       //Verändert Variable position mit der aktuellen Position i
          break;                             //beendet die for-Schleife bei Treffer
        }
      }

      if (position != -1)   //Wenn das Zeichen gefunden wurde, wird der zugehörige Morsecode verarbeitet
      { //Gibt das gefundene Zeichen und seinen Morsecode im Serial-Monitor aus
        Serial.print(gesucht);
        Serial.print(": ");
        Serial.println(morse[position]);  //Gibt den Morsecode von der gleichen Array-Position mit Zeilenumbruch aus

        //Verarbeitet die einzelnen Punkte und Striche des gefundenen Morsecodes
        for (int i=0; i < morse[position].length(); i++)  //morse[position].length()bestimmt wie viele Morsezeichen durchlaufen werden müssen
        {
          if (morse[position][i] == '.')                //Prüft ob das aktuelle Morsezeichen ein Punkt ist
          {
            punkt();                                  //Führt Funktion punkt() aus wenn '.' 

          }

          else if (morse[position][i] == '-')
          {
            strich();                           //führt Funktion strich() aus wenn '-'

          }
          if (i< morse[position].length()-1)  //Prüft ob das aktuelle Morsezeichen nicht das letzte Zeichen ist
          {
            delay(100);                     //macht eine Pause von 100ms zwischen jedem Zeichen de Strings außer beim letzten Zeichen 
          }

        }
      }

      else if (gesucht != ' ')         //Wenn kein Treffer gefunden wurde und das Zeichen kein Leerzeichen ist

      {
        Serial.print("Zeichen '");
        Serial.print(gesucht);
        Serial.println("' nicht gefunden!");  //Gibt Fehlermeldung, falls postion -1 bleibt
      }
      zaehler = zaehler +1;                 //Erhöht den Index der Eingabe um 1, damit das nächste Zeichen verarbeitet wird

      //Steuert die Pausen zwischen den Buchstaben und Wörtern
      if (zaehler < eingabe.length() && eingabe[zaehler] != ' ' && gesucht != ' ')  //Prüft ob noch ein Zeichen folgt und weder das vorherige noch das nächste Zeichen ein Leerzeichen ist
          {
            delay(300);
          }
      else if (zaehler < eingabe.length() && eingabe[zaehler] == ' ')            //Prüft ob noch ein Zeichen folgt und dieses ein Leerzeichen ist
      {
        delay(700);
      }
    }
    Serial.println("Text zum Morsen eingeben:");  
  }
}
