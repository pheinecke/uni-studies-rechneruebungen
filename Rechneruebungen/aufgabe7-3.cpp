#include <iostream>
using namespace std;

int main()
{
int anzahl=0;
int *artikel_ptr = NULL;
float *preis_ptr = NULL;
	
cout << "\nArtikel Anzahl eingeben!" << endl;
cin >> anzahl;

artikel_ptr = new int[anzahl];
preis_ptr = new float[anzahl];

for(int i=0;i<anzahl;i++)
	{
	cout << "\nArtikel " << i+1 << ": Zuerst Artikel-Nummer, dann Preis eingeben!" << endl;
	cin >> artikel_ptr[i];
	cin >> preis_ptr[i];
	}

cout << "\n\n == P R E I S L I S T E ==" << endl;
cout << "\nNr.   |  Preis" << endl;
cout << "-----------------------------" << endl;

for(int j=0;j<anzahl;j++)
{
cout << artikel_ptr[j] << "       " <<preis_ptr[j] << endl;	
}

delete artikel_ptr;
delete preis_ptr;
artikel_ptr = NULL;
preis_ptr = NULL;

return 0;	
}