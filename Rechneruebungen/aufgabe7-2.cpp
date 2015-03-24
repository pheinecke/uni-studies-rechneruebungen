#include <iostream>

using namespace std;

void summenKrit(double** a, int n, int* zeilKrit, int* spaltKrit);

int main()
{
	// Matrix initialisieren
	double matrix[5][5]= {{5.3, 1.0, 0.0, 0.0, 0.0}, 
		              {2.2, 5.8, 2.1, 0.0, 0.3},
                              {1.2, 3.0, 6.0, 2.0, 1.0},
		              {0.0, 0.0, 2.0, 4.0, 0.0},
                              {1.2, 2.0, 2.2, 3.0, 8.4}};

	// Feld von Zeigern fuer Uebergabe an Funktion initialisieren
	double* a[5] = {matrix[0],matrix[1],matrix[2],matrix[3],matrix[4]};
	
	// Felder fuer Ergebnisse definieren
	int zeilKrit[5] = {0};
	int spaltKrit[5] = {0};

	// Funktionsaufruf
	summenKrit(a, 5, zeilKrit, spaltKrit);

	// Ausgabe der Ergebnisse auf den Bildschirm
	for (int i=0; i < 5; i++)
	{
		cout << endl << "Diagonalelement " << i+1 << ":" << endl;
		if (zeilKrit[i]==1) cout << "Zeilensummenkriterium ist erfuellt." << endl;
		if (spaltKrit[i]==1) cout << "Spaltensummenkriterium ist erfuellt." << endl;
		if ((zeilKrit[i]==0)&&(spaltKrit[i]==0)) cout << "Keines der Kriterien ist erfuellt." << endl;
	}
	
	return 0;
}

void summenKrit(double** a, int n, int* zeilKrit, int* spaltKrit)
{
double zeilensumme=0;
double spaltensumme=0;
	
	for(int i=0;i<n;i++)
		{
			zeilensumme=0;
			spaltensumme=0;
			
			for(int j=0;j<n;j++)
			{
			zeilensumme+=a[i][j];
			}
			for(int k=0;k<n;k++)
			{
			spaltensumme+=a[k][i];
			}
			
			if((zeilensumme-a[i][i])<a[i][i])
			{
				zeilKrit[i]=1;
			}
			if((spaltensumme-a[i][i])<a[i][i])
			{
				spaltKrit[i]=1;
			}
		}
	
}