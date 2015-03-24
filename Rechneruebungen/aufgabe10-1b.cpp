//bsp10-5A.cpp
#include <iostream>
using namespace std;

// Grundstücksklasse
class grundstueck {                            // Definition Klasse Grundstück
    
    public:
        grundstueck(int nummer);               // Konstruktorprototyp - dient zur Initialisierung
	grundstueck(int nummer, double preis, double flaeche); // Konstruktor überladen
    
        double getFlaeche();                   // Methodenprototypen
        double getPreis();        
        int getNummer();        
        void setPreis(double preis);
        void setFlaeche(double flaeche);
        double getQMPreis();
        
    private:
        double flaeche;                        // Attribut-definitionen
        double preis;
        int nummer;
};

// K O N S T R U K T O R D E F I N I T I O N E N
// Definition des 1. Konstruktors
grundstueck::grundstueck(int nummer) {
    this->nummer = nummer;
    this->flaeche = 0.0;
    this->preis = 0.0;
}

grundstueck::grundstueck(int nummer, double preis, double flaeche){
this->nummer = nummer;
this->preis = preis;
this->flaeche = flaeche;	
}

// M E T H O D E N D E F I N I T I O N E N
double grundstueck::getQMPreis(){
return (this->preis)/(this->flaeche);	
}

void grundstueck::setPreis(double preis){
    this->preis = preis;
}

double grundstueck::getPreis(){
    return this->preis;
}

void grundstueck::setFlaeche(double flaeche){
    this->flaeche = flaeche;
}

double grundstueck::getFlaeche(){
    return this->flaeche;
}

int grundstueck::getNummer(){
    return this->nummer;
}


// H A U P T P R O G R A M M
int main() {                                               
    grundstueck parz1(42);                          // Instanziierung Objekt der Klasse grundstueck mit der Nummer 42
	
	grundstueck parz2(1337, 37500.0,1200.0);

    parz1.setFlaeche(1000);
    parz1.setPreis(30000);
    
    cout << "Grundstuecksnr = " << parz1.getNummer() 
         << "  ;  Flaeche = " << parz1.getFlaeche()
         << "  ;  Grundstueckspreis = " << parz1.getPreis() 
	<< "  ; Quadratmeterpreis = " << parz1.getQMPreis() << endl;
	
	cout << "Grundstuecksnr = " << parz2.getNummer() 
         << "  ;  Flaeche = " << parz2.getFlaeche()
         << "  ;  Grundstueckspreis = " << parz2.getPreis() 
	<< "  ; Quadratmeterpreis = " << parz2.getQMPreis() << endl;
    
    
    return 0;
}

