#include <iostream>

using namespace std;

int main()
{
char zeichen;
int zahl;

cout << "\nZeichen eingeben!\n";
cin >> zeichen;

//zahl = staic_cast<int>(zeichen);
zahl = int(zeichen); //Zeichen zahl zuordnen

cout << "\nDas eingebene Zeichen lautet:" << zeichen << endl; // Ausgabe Zeichen
cout << "\nBewertung als Zahl:" << zahl << endl; // Ausgabe Zahl

cout << "\nDie Eingabe ist vom Typ: ";

/*switch (zeichen)
{
  case "a":
  case "b":
  case "c":
  case "d":
  case "e":
  case "f":
  case "g":
  case "h":
  case "i":
  case "j":
  case "k":
  case "l":
  case "m":
  case "n":
  case "o":
  case "p":
  case "q":
  case "r":
  case "s":
  case "t":
  case "u":
  case "v":
  case "w":
  case "x":
  case "y":
  case "z":
    cout << "Kleinbuchstabe" << endl;
    break;
  case "A":
  case "B":
  case "C":
  case "D":
  case "E":
  case "F":
  case "G":
  case "H":
  case "I":
  case "J":
  case "K":
  case "L":
  case "M":
  case "N":
  case "O":
  case "P":
  case "Q":
  case "R":
  case "S":
  case "T":
  case "U":
  case "V":
  case "W":
  case "X":
  case "Y":
  case "Z":
    cout << "Grossbuchstabe" << endl;
    break;
  case "0":
  case "1":
  case "2":
  case "3":
  case "4":
  case "5":
  case "6":
  case "7":
  case "8":
  case "9":
    cout << "Zahl" << endl;
    break;
  default:
    cout << "Sonstiges" << endl;
}*/

if(zahl>64 && zahl<91)
{cout << "Grossbuchstabe\n\n";}
else if (zahl>96 && zahl<123)
{cout << "Kleinbuchstabe\n\n";}
else
{cout << "Sonderzeichen\n\n";}




return 0;
}
