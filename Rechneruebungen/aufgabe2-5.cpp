#include <iostream>

using namespace std;

int main() 
	{
	char defgeo;
	
	cout << "\nGeometrie waehlen!\n\n - k fuer Kreis\n - r fuer Rechteck\n - d fuer rechtwinkliges Dreieck\n"; 
	cin >> defgeo; 																		//Abfrage Geometrie
	cout << "\n------------------------------------------------------------------------------\n";

	//Kreis
		if(defgeo=='k' or defgeo=='K')
		{
			double radius;
			double pi = 3.1415;
			cout << "\nRadius?\n";
			cin >> radius;
			
			cout << "\n------------------------------------------------------------------------------\n";
			cout << "\n   Kreisflaeche betraegt:" << pi*(radius*radius) << "\n\n\n";
			
			
		}
		
	//Viereck
		else if(defgeo=='r' or defgeo=='R')
		{
			double seitenlaenge1, seitenlaenge2;
			cout << "\nSeitenlaenge 1?\n";
			cin >> seitenlaenge1;
			cout << "\nSeitenlaenge 2?\n";
			cin >> seitenlaenge2;
			
			cout << "\n------------------------------------------------------------------------------\n";
			cout << "\n   Flaeche des Rechtecks betraegt:" << seitenlaenge1*seitenlaenge2 << "\n\n\n";
			
		}
		
	//Dreieck
		else if(defgeo=='d' or defgeo=='D')
		{
			double breite, hoehe;
			cout << "\nBreite?\n";
			cin >> breite;
			cout << "\nHoehe?\n";
			cin >> hoehe;
			
			cout << "\n------------------------------------------------------------------------------\n";
			cout <<"\n   Flaeche des Dreieckes betraegt:" << (hoehe*breite)/2 << "\n\n\n";
			
		}
	//Ungültige Eingabe	
		else
		{
		cout << "\n              Fehler: Bitte eine gueltige Geometrie waehlen.\n";

		}
	return 0;
	}