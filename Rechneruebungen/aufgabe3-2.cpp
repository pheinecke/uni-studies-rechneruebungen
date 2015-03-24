#include <iostream>

using namespace std;

int main()
	{
	float ganzZahl;
	int test1;
	float test2;
	
	cout << "\nBitte eine ganze Zahl eingeben." << endl;
	cin >> ganzZahl;
	
	test1 = int(ganzZahl);
	test2 = float(test1);
	
	while(ganzZahl<=0 || test2!=ganzZahl)
		{
		cout << "\nKeine ganze, positive Zahle angegeben. Eingabe wiederholen!" << endl;
		cin >> ganzZahl;
		test1 = int(ganzZahl);
		test2 = float(test1);
		}
	
	int i=1;
	int ergebnis=1;
	do
		{
		ergebnis=ergebnis*i;
		i=i++;
		}
	while(i<=ganzZahl);
	
	cout << ganzZahl << "! = " << ergebnis << endl;
		
	return 0;
	}
