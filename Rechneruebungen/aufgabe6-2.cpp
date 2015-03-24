#include <iostream>
using namespace std;

void momber(double laenge, double kraft[3], double moment[3]);

int main()
{
	double laenge = 0.0;
	
	cout << "\nLaenge eingeben!" << endl;
	cin >> laenge;
	
	double kraft[3] = {0,0,0};
	
	cout << "\nx-Komponente der Kraft eingeben!" << endl;
	cin >> kraft[0];
	
	cout << "\ny-Komponente der Kraft eingeben!" << endl;
	cin >> kraft[1];	
	
	cout << "\nz-Komponente der Kraft eingeben!" << endl;
	cin >> kraft[2];

	double moment[3] = {0,0,0};

	momber(laenge, kraft, moment);
	
	cout << "\nMomentenvektor: (";
	for(int idx=0;idx<=2;idx++)
	{
	cout << moment[idx];
	if (idx<2) {cout << ", ";}
	}
	cout << ")^T" << endl;
	
return 0;	
}

void momber(double laenge, double kraft[3], double moment[3])
{
laenge=laenge;
kraft=kraft;
moment=moment;
	
moment[0]=0;
moment[1]=kraft[2]*laenge;
moment[2]=kraft[1]*laenge;

}


