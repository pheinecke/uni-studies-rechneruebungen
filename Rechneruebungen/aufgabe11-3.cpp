#include <iostream>					// Praeprozessoranweisung
#include <limits>
using namespace std;

// Klassendefinition:
class Konto
{
	private:
		char kontoinhaber[20];
		int kontonummer;
		float kontostand;
		static int anzahl_konten;
	
	public:
		void setzeKontoinhaber(char*);
		char* gibKontoinhaber();
		int gibKontonummer();
		float gibKontostand();
		void einzahlen(float);
		void abheben(float&);
		Konto();
		static int gibAnzahl_konten();
};

Konto::Konto()
{
	anzahl_konten=anzahl_konten+1;
	kontonummer=anzahl_konten;
}

int Konto::gibAnzahl_konten()
{
	return anzahl_konten;
}



int Konto::anzahl_konten=0;
// Definition der Methoden der Klasse Konto:
void Konto::setzeKontoinhaber(char* name)
{
	// Speicherueberlauf vermeiden: Letztes Element auf "Stringende" setzen:
	kontoinhaber[19] = '\0';
	// Nur Elemente 1 bis 19 uebertragen:
	for (int i = 0; i < 19; i++)
	{
		kontoinhaber[i] = name[i];
	}
}

char* Konto::gibKontoinhaber()
{
	return kontoinhaber;
}

int Konto::gibKontonummer()
{
	return kontonummer;
}

float Konto::gibKontostand()
{
	return kontostand;
}

void Konto::einzahlen(float betrag)
{
	kontostand += betrag;
}

void Konto::abheben(float& betrag)
{
	if (kontostand >= betrag)
	{
		kontostand -= betrag;
	}
	else
	{
		betrag = kontostand;
		kontostand = 0;
	}
}


// Definition der Funktion kontoAnlegen
bool kontoAnlegen (Konto& konto)
{
	char inhaber[20];
	float stand = 0.0;
	
	cout << "Anlegen des " << konto.gibKontonummer() << ". Kontos von " << Konto::gibAnzahl_konten()  << endl;
	
	cout << "Geben Sie den Kontoinhaber ein (max. 20 Zeichen): ";
	cin >> inhaber;
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Diese Zeile verhindert, dass eine Endlosschleife
														// bei Eingabe eines Leerzeichens auftritt
	cout << "Geben Sie den Anfangskontostand ein: ";
	cin >> stand;
	
	// Zur Sicherheit: Kontostand auf 0 setzen
	float stand_alt = konto.gibKontostand();
	konto.abheben(stand_alt);
	
	// Attribute setzen
	konto.setzeKontoinhaber(inhaber);
	konto.einzahlen(stand);
	
	return true;
}


// Hauptfunktion
int main()									// Funktionskopf
{
	int anzahl = 0;
	Konto* kto_ptr = NULL;
	bool status = false;
	int auswahl = -1;
	int ein_aus = -1;
	float betrag = 0.0;
	
	cout << "Wie viele Konten sollen angelegt werden: ";
	cin >> anzahl;
	
	// Speicher anfordern
	kto_ptr = new Konto[anzahl];
	
	// Konten anlegen
	for (int i = 0; i < anzahl; i++)
	{
		status = kontoAnlegen(kto_ptr[i]);
	}
	
	// Kontenuebersicht ausgeben (mit Auswahlmoeglichkeit)
	cout << endl;
	cout << " Auswahl | Kontonr. | Inhaber | Stand" << endl;
	for (int i = 0; i < anzahl; i++)
	{
		cout << " (" << i << ") | " << kto_ptr[i].gibKontonummer() << " | " << kto_ptr[i].gibKontoinhaber()
		     << " | " << kto_ptr[i].gibKontostand() << endl;
	}
	
	do
	{
		cout << endl;
		cout << "Auswahl des zu bearbeitenden Kontos: ";
		cin >> auswahl;
	}
	while ((auswahl < 0) || (auswahl >= anzahl));
		
	cout << "(0) - Einzahlen" << endl;
	cout << "(1) - Abheben" << endl;
	do
	{
		cout << "Auswahl: ";
		cin >> ein_aus;
	}
	while ((ein_aus < 0) || (ein_aus >= 2));
	
	cout << "Betrag: ";
	cin >> betrag;
	
	cout << "Kontostand alt: " << kto_ptr[auswahl].gibKontostand() << endl;
	switch (ein_aus)
	{
		case 0:
			kto_ptr[auswahl].einzahlen(betrag);
			break;
		case 1:
			kto_ptr[auswahl].abheben(betrag);
			break;
	}
	cout << "Kontostand neu: " << kto_ptr[auswahl].gibKontostand() << endl;
	
	// Kontenuebersicht ausgeben
	cout << endl;
	cout << "Kontonr. | Inhaber | Stand" << endl;
	for (int i = 0; i < anzahl; i++)
	{
		cout << kto_ptr[i].gibKontonummer() << " | " << kto_ptr[i].gibKontoinhaber()
				 << " | " << kto_ptr[i].gibKontostand() << endl;
	}
	
	// Speicher freigeben
	delete [] kto_ptr;
	kto_ptr = NULL;
	
	return 0;
}														// Funktionsende
