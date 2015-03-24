#include <iostream>					// Präprozessoranweisung

using namespace std;

// Diese Datei enthaelt eine kurze Hauptfunktion, die zum Testen der Klasse
// Konto verwendet werden kann. Es wird ein Objekt der Klasse Konto instanziiert
// und die einzelnen Methoden der Klasse der Reihe nach angesprochen. Dabei entsteht
// eine Bildschirmausgabe der Attribute des Objekts.

// Kopieren Sie diese Hauptfunktion in die Quelldatei, in der Sie die Klassendefinition
// und die Methodendefinitionen der Klasse Konto geschrieben haben.

// Hauptfunktion
int main()									// Funktionskopf
{
	Konto testkonto;

	// Methoden vom Typ "setze" ansprechen:
	testkonto.setzeKontoinhaber("MusterKunde");
	testkonto.setzeKontonummer(123456);

	// Methoden einzahlen und abheben ansprechen
	// (diese Aufrufe auskommentieren, falls die Methoden noch
	//  nicht definiert sind)
	float betrag1 = 5000;
	float betrag2 = 2000;
	testkonto.einzahlen(betrag1);
	testkonto.abheben(betrag2);

	// Methoden com Typ "gib" ansprechen
	// (Diese Methoden haben einen Rueckgabewert!)
	char* inhaber = testkonto.gibKontoinhaber();
	int nummer = testkonto.gibKontonummer();
	float stand = testkonto.gibKontostand();

	// Bildschirmausgabe:
	cout << "Kontoinhaber: " << inhaber << endl;
	cout << "Kontonummer:  " << nummer << endl;
	cout << "Kontostand:   " << stand << endl;
	
	return 0;
}														// Funktionsende
