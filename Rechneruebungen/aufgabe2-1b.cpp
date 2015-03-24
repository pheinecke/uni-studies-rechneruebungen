#include <iostream>

using namespace std;

int main()
	{
	float zahl1, zahl2;

	cout << "\nBitte Zahl 1 eingeben.\n";
	cin >> zahl1;
	cout << "\nBitte Zahl 2 eingeben.\n";
	cin >> zahl2;
	
	cout << "Summe:" << zahl1 + zahl2 << endl;
	cout << "Differenz:" << zahl1 - zahl2 << endl;
	cout << "Produkt:" << zahl1 * zahl2 << endl;
	if(zahl2==0)
		{cout << "Quotient: FAIL!\n";} //Fehlerausgabe bei teilen durch 0
	else 
		{cout << "Quotient:" << zahl1/zahl2 << endl;}//Ausgabe Quotient bei zahl2!=0
		

	return 0;
	}

