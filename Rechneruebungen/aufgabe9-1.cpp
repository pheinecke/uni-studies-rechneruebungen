#include <iostream>					// Präprozessoranweisung

using namespace std;

// Definition einer Klasse, die in der Lage ist, Vektoren zu speichern
class vektor {
	private:
		int laenge;
		double *daten;
	
	public:
		vektor(int laenge0);
		void setzeLaenge(int l);
		int gibLaenge();
		void setzeDaten(double* dat);
		void setzeElement(int index, double elem);
		void printDaten();
};

// Methodendefinitionen
vektor::vektor(int laenge0){
this->laenge=laenge0;
this->daten = new double[laenge0];	
}

/*void vektor::setzeLaenge(int l)
{
	this->laenge = l;
	delete this->daten;
	this->daten = NULL;
	this->daten = new double[this->laenge];
}*/

int vektor::gibLaenge()
{
	return this->laenge;
}

void vektor::setzeDaten(double* dat)
{
	for (int i = 0; i < this->laenge; i++)
	{
		this->daten[i] = dat[i];
	}
}

void vektor::setzeElement(int index, double elem)
{
	this->daten[index] = elem;
}

void vektor::printDaten()
{
	cout << endl << "Datenausgabe: Vektor der Laenge " << this->laenge << endl;
	for (int i = 0; i < this->laenge; i++)
	{
		cout << "Element [" << i << "] : " << this->daten[i] << endl;
	}
}


// Prototyp der Funktion kopiedemo (wird erst in Aufgabe 9-3 gebraucht)
void kopiedemo(vektor kopie);


// Hauptfunktion
int main()									// Funktionskopf
{
	// Objekt der Klasse Vektor instanziieren:
	vektor vek1(3);
	
	// Werte zuweisen:
	// vek1.setzeLaenge(3);
	double eingabefeld[3] = {1.0,-7.5,3.54};
	vek1.setzeDaten(eingabefeld);
	
	// Inhalt des Vektors ausgeben:
	vek1.printDaten();
	
	return 0;
}														// Funktionsende


// Definition der Funktion kopiedemo (wird erst in Aufgabe 9-3 gebraucht)
void kopiedemo(vektor kopie)
{
	// Erstes Element im kopierten Vektor veraendern
	kopie.setzeElement(0, 42.23);
	
	// kopierten Vektor ausgeben
	cout << endl << "Kopie:" << endl;
	kopie.printDaten();
}
