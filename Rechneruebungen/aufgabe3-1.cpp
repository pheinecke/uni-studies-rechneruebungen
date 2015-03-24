#include <iostream>

using namespace std;

int main()
	{
	float anfang, ende, delta;
	
	cout << "\nStartwert, Endwert und Inkrement eingeben und jeweils mit Enter bestaetigen!" << endl;
	cin >> anfang;
	cin >> ende;
	cin >> delta;
	
	while (anfang>=ende || delta<=0 || delta>ende-anfang)
		{
		cout << "\nAngaben nicht sinnvoll. Eingabe wiederholen!" << endl;
		cin >> anfang;
		cin >> ende;
		cin >> delta;	
		}
		
		cout << "\nWertetabelle\n" << endl;

		
	for (float x=anfang; x<=ende; x=x+delta)
		{

		cout << "f(" << x << ")=" << (x*x)+3 << endl;
		
		}

	return 0;	
	}

