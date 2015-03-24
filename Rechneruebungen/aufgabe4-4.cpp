// bsp4-4.cpp Rekursive Reihenentwicklung der Sinusfunktion
#include <iostream>		// Praeprozessor-Anweisungen
using namespace std;

// Prototypen der zu verwendenden Funktionen
float sinusReihe(int n, float x);     // zu definierende Funktion
float potenz(float, int);
int fakultaet(int);                         // Funktion bekannt aus Saaluebung_4

int main(void)			// Kopf Hauptprogramm
{						
  int ordnung;
  float x;
  
  // Einlesen der Daten
  cout << "Bitte Winkel in RAD als Kommazahl eingeben: " << endl;
  cin >> x;
  cout << "Bitte Naeherungsordnung als Ganzzahl eingeben: " << endl;
  cin >> ordnung;
  
  // Datenausgabe
  cout << "\nSinus von " << x <<" (rad) ist " << sinusReihe(ordnung, x) << endl;
  cout << "(Naeherung der Ordnung " << ordnung <<")\n" << endl;
  
  return 0;		// Rückgabe 0 
}

// Funktion zur Berechnung der Sinus-Reihenentwicklung

float sinusReihe(int n, float x)
{
float ergebnis = 0;
	for(int i=0;i<=n;i++){
		ergebnis=ergebnis+(potenz(-1,i)* (potenz(x,2*i+1)/fakultaet(2*i+1)));
	}
return ergebnis;
}


// Funktion zur Berechnung "x hoch n", hoffentlich bekannt aus Vorlesung
/*float potenz(float x, int n){
    float potenz=1.0;
    for (int i=1; i<=n; i++){
        potenz *= x; }
    return potenz;
}*/

// Potenz als rekursive Variante
float potenz(float x, int n){
	if(n==0){return 1;}
	else {n=n-1;
		return x*potenz(x,n);
		}
	
}

// Funktion zur Berechnung der Fakultaet, bekannt aus Saaluebung_4
/*int fakultaet (int zahl){
	int fak=1;
	for (int a=1; a<=zahl; a++){
		fak *= a; }
	return fak;
}*/

// Fakultaet als rekursive Variante
int fakultaet (int zahl){
	if(zahl==0){return 1;}
	else { return zahl*fakultaet(zahl-1);}
