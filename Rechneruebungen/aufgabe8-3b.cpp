#include <iostream>
using namespace std;

class Konto {
	private:
		char kontoinhaber[20];
		int kontonummer;
		float kontostand;
		
	public:
		void set_kontoinhaber(char*);
		char* get_kontoinhaber();
		void set_kontonummer(int);
		int get_kontonummer();
		float get_kontostand();
		void einzahlen(float);
		void auszahlen(float);
};

// Methodendefinitionen
void Konto::set_kontoinhaber(char* neu_kontoinhaber) {
	for(int i=0;i<20;i++)
		{
		kontoinhaber[i]=neu_kontoinhaber[i];	
		}
}

char* Konto::get_kontoinhaber(){
	return kontoinhaber;
}

void Konto::set_kontonummer(int neu_kontonummer){
	kontonummer=neu_kontonummer;
}

int Konto::get_kontonummer(){
	return kontonummer;
}

float Konto::get_kontostand(){
	return kontostand;
}

void Konto::einzahlen(float betrag){
	kontostand+=betrag;
}

void Konto::auszahlen(float betrag){
	if(betrag<=kontostand){
		kontostand-=betrag;
	}
	else{
		cout << "Auszahlung nicht moeglich. Sie haben lediglich noch " << kontostand <<" EUR auf dem Konto." << endl;
	}
}

// Funktion zum Anlegen eines Kontos

bool konto_anlegen(Konto &);
bool konto_anlegen(Konto &neuesKonto_ptr){					//Parameter: Referenz auf Objekt der Klasse Konto
	
	char temp_name[20];
	int temp_nummer;
	float temp_stand;
	
	cout << "\n== Anlegen eines neuen Kontos ==" << endl;
	cout << "Bitte Kontoinhaber eingeben" << endl;
	cin >> temp_name;
	cout << "Bitte Kontonummer eingeben" << endl;
	cin >> temp_nummer;
	cout << "Bitte Kontostand eingebben" << endl;
	cin >> temp_stand;
	
	neuesKonto_ptr.set_kontoinhaber(temp_name);		//Setzen der Infos für das Objekt per Methoden der Klasse Konto
	neuesKonto_ptr.set_kontonummer(temp_nummer);		//Zugriff über Zeiger auf Objekt der Klasse Konto
	neuesKonto_ptr.einzahlen(temp_stand);
	
return true;	
}

// Main Funktion
int main()
{
	int anzahl=0;											//Anzahl anzulegender Konten abfragen
	do{													//Prüfen, ob Eingabe sinnvoll
	cout << "Anzahl neu anzulegender Konten eingeben." << endl;
	cin >> anzahl;}
	while(anzahl<=0);
	
	Konto *konto_ptr = new Konto[anzahl];						//dyn. Anforderung von Speicher für Objektfeld der Klasse Konto
	
	for(int i=0;i<anzahl;i++)
		{
		konto_anlegen(konto_ptr[i]);							//Aufruf der Funktion. Parameter ist Zeiger auf Objekt aus dem Objektfeld
		}
	
	cout << "\n== Kontenuebersicht ==\n" << endl;
	cout << "Lfd Nr.  " << "Kontonummer  " << "Kontostand  " << "Kontoinhaber"<< endl;
	cout << "----------------------------------------------" << endl;
	
	for(int i=0;i<anzahl;i++)								//Kontoinfos ausgeben
		{
		cout << i+1 << "           ";
		cout << konto_ptr[i].get_kontonummer() << "     ";		//Aufruf über Methoden der Konto Klasse. Zugriff über Zeiger auf Objekte des Objektfeldes
		cout << konto_ptr[i].get_kontostand() <<"  ";
		cout << konto_ptr[i].get_kontoinhaber()  << endl;
		}
		
	int auswahl=0;										//Konto auswählen. Sinnhaftigkeit prüfen
	do{
	cout << "\nWaehlen Sie ein Konto, um eine Aus- oder Einzahlung vorzunehmen." << endl;
	cin >> auswahl;
	}
	while(auswahl<1 || auswahl>anzahl);
	

	
	int vorgang;							//Vorgang auswählen, Sinnhaftigkeit der Eingabe prüfen.
	do{
	cout << "\nBitte auswaehlen:" << endl;
	cout << "(1) Einzahlen\n(2) Auszahlen" << endl;
	cin >> vorgang;
		}
	while(vorgang!=1 && vorgang!=2);
	
	float betrag;							//Vorgang durchführen und Werte zurückgeben. Zugriff über Methoden und Zeiger auf Objekte des Objektfeldes der Konto Klasse
	switch(vorgang){
		case 1:
			cout << "\nBitte geben Sie den einzuzahlenden Betrag ein" << endl;
			cin >> betrag;
			while(betrag<=0.0){
				cout << "Eingabe ungültig, bitte wiederholen!"<< endl;
				cin >> betrag;
			}
			konto_ptr[auswahl-1].einzahlen(betrag);
			cout << "Vorgang ausgefuehrt -- Alter Kontostand: " << konto_ptr[auswahl-1].get_kontostand() - betrag << " EUR  Neuer Kontostand: " << konto_ptr[auswahl-1].get_kontostand() << " EUR" << endl;
			break;
		case 2:
			cout << "\nBitte geben Sie den auszuzahlenden Betrag ein" << endl;
			cin >> betrag;
			while(betrag<=0.0){
				cout << "Eingabe ungültig, bitte wiederholen!"<< endl;
				cin >> betrag;
			}
			konto_ptr[auswahl-1].auszahlen(betrag);
			cout << "Vorgang ausgefuehrt -- Alter Kontostand: " << konto_ptr[auswahl-1].get_kontostand() + betrag << " EUR  Neuer Kontostand: " << konto_ptr[auswahl-1].get_kontostand() << " EUR" << endl;
			break;
		
	}
	
delete [] konto_ptr; //dyn. angeforderten Speicher freigeben
konto_ptr = NULL;
return 0;	
}

