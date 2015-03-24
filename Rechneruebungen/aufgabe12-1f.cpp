//aufgabe12-1.cpp
#include <iostream>
#include <cmath>
using namespace std;

class Figur {  
    protected:
		// Attribute:
      double x_MP;
      double y_MP;
      double z_MP;
      double flaeche;
    public:
		// Methoden:
      void setze_MP(double x, double y, double z);
      void print_MP();
      virtual void info();
      virtual void berechne_flaeche()=0;
      Figur();
      Figur(double, double, double);
};

Figur::Figur(){
	setze_MP(0,0,0);
}

Figur::Figur(double x, double y, double z){
	setze_MP(x, y, z);
}

class Kreis:public Figur {
    private:
		// Attribute:
      double radius;
    public:
		// Methoden:
      void setze_radius(double r);
      virtual void berechne_flaeche();
      virtual void info();
      Kreis();
      Kreis(double, double, double);
};

Kreis::Kreis(double x, double y, double z):Figur(x, y, z);

class Rechteck:public Figur {
	private:
		double laenge;
		double breite;
	public:
		void set_kanten(double, double);
		virtual void berechne_flaeche();
		virtual void info();
		Rechteck();
		Rechteck(double, double, double);	
};

Rechteck:Rechteck(double x, double y, double z):Figur(x, y, z);

// H A U P T P R O G R A M M
int main()
{
	// Feld der Basisklasse anlegen
	Figur* figurenfeld[3];
	// Objekte verschiedener Klassen instantiieren
	Rechteck fig1;
	Kreis kreis1, kreis2;
	// Radii der Kreise setzen
	kreis1.setze_radius(1.0);
	kreis2.setze_radius(3.0);
	//Kantenlaenge des Rechtecks setzen
	fig1.set_kanten(5.0, 3.0);
	// Feld belegen
	figurenfeld[0] = &fig1;
	figurenfeld[1] = &kreis1;
	figurenfeld[2] = &kreis2;
	// Methoden in einer Schleife aufrufen
	for (int i = 0; i < 3; i++)
	{
		cout << endl << "Figur Nr. " << i+1 << endl;
		figurenfeld[i]->berechne_flaeche();
		figurenfeld[i]->info();
	}
	
    return 0;
}

// M E T H O D E N D E F I N I T I O N E N
// Methoden der Basisklasse
void Figur::setze_MP(double x, double y, double z)
{
	x_MP = x;
	y_MP = y;
	z_MP = z;
}
void Figur::print_MP()
{
	cout << "Mittelpunkt:" << endl;
	cout << "X : " << x_MP << endl;
	cout << "Y : " << y_MP << endl;
	cout << "Z : " << z_MP << endl;
}
void Figur::info()
{
	cout << endl << "Dies ist eine Figur" << endl;
}


// Methoden der abgeleiteten Klasse(n)
void Kreis::setze_radius(double r)
{
	radius = r;
}
void Kreis::berechne_flaeche()
{
	const double pi = 2*asin(1);
  flaeche = pi * radius * radius;
}
void Kreis::info()
{
	cout << endl << "Dies ist ein Kreis" << endl;
	cout << "Flaeche: " << flaeche << endl;
}

void Rechteck::set_kanten(double l, double b){
	laenge=l;
	breite=b;
}

void Rechteck::berechne_flaeche(){
	flaeche=laenge*breite;
}

void Rechteck::info(){
	cout << endl << "Dies ist ein Rechteck" << endl;
	cout << "Flaeche: " << flaeche << endl;
}

