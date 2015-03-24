#include <iostream>					// Praeprozessoranweisung

using namespace std;

// Klassendefinition:
class Artikel
{
	protected:
		char bezeichnung[20];
		int menge;
		double preis;

	public:
		Artikel(char* bez, double p);
		void einkaufen(int anzahl);
		void verkaufen(int anzahl);
};

class Lebensmittel:public Artikel
{
	private:
		int haltbarkeit;
	public:
		Lebensmittel(int haltb, char* bez, double preis);
		void preis_neu();
};

class Moebel:public Artikel
{
	private:
		
	public:
		Moebel(char* bez, double preis);
		void preis_neu();
};

// H A U P T F U N K T I O N
int main()
{
	// Ein Objekt fuer einen Artikel instanziieren
	Lebensmittel bananen(2, "Bananen", 0.75);
	
	// Bananen kaufen
	bananen.einkaufen(2500);
	
	// Bananen verkaufen
	bananen.preis_neu();
	bananen.verkaufen(2500);
	
	
	// Ein Objekt fuer einen weiteren Artikel instanziieren
	Moebel schraenke("Schraenke", 250.0);
	
	// Schraenke einkaufen
	schraenke.einkaufen(135);
	
	// Schraenke verkaufen
	schraenke.preis_neu();
	schraenke.verkaufen(135);
	
	return 0;
}


// M E T H O D E N D E F I N I T I O N E N
// Konstruktor
Artikel::Artikel(char* bez, double p)
{
	// Speicherueberlauf vermeiden: Letztes Element auf "Stringende" setzen:
	bezeichnung[19] = '\0';
	// Nur Elemente 1 bis 19 uebertragen:
	for (int i = 0; i < 19; i++)
	{
		bezeichnung[i] = bez[i];
	}
	
	preis = p;
	
	menge = 0;
}

Lebensmittel::Lebensmittel(int haltb, char* bez, double preis):Artikel(bez, preis)
{
haltbarkeit = haltb;
}

Moebel::Moebel(char* bez, double preis):Artikel(bez, preis)
{
	
}

void Lebensmittel::preis_neu()
{
	if(haltbarkeit<3){preis=0.5*preis;}
}

void Moebel::preis_neu()
 {
	 if(menge>130)
	 {
		 preis=preis*0.75;
	 }
 }

void Artikel::einkaufen(int anzahl)
{
	menge += anzahl;
	double kosten = preis * anzahl;
	// Ausgabe
	cout << endl;
	cout << "Der Einkauf von " << anzahl << " " << bezeichnung << " kostet Sie " << kosten << " Euro." << endl;
	cout << "(Einzelpreis: " << preis << " Euro.)" << endl;
	cout << "Sie haben jetzt " << menge << " " << bezeichnung << "." << endl;
}

void Artikel::verkaufen(int anzahl)
{
	// Vermeiden, dass mehr verkauft wird, als vorhanden ist
	if (anzahl > menge) anzahl = menge;
	menge -= anzahl;
	double kosten = preis * anzahl;
	// Ausgabe
	cout << endl;
	cout << "Der Verkauf von " << anzahl << " " << bezeichnung << " bringt Ihnen " << kosten << " Euro." << endl;
	cout << "(Einzelpreis: " << preis << " Euro.)" << endl;
	cout << "Sie haben jetzt " << menge << " " << bezeichnung << "." << endl;
}
