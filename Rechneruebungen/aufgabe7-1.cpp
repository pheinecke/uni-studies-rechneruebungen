#include <iostream>					// Präprozessoranweisung

using namespace std;

void fkt_eingabe(float**, float*, int);                 // Funktionsprototypen
void fkt_berechnung(float**, float*, float*, int);


int main()						// Funktionskopf
{
	//Variablen
	float sigma[3]={0.0}, epsilon[3];
	float matrix[3][3]={0.0};
        float* feld[3]={matrix[0], matrix[1], matrix[2]};
	
	//Eingabe
        fkt_eingabe(feld, epsilon, 3);
	
	//Berechnung
	fkt_berechnung(feld, sigma, epsilon, 3);
	
	//Ausgabe
	cout << "Resultierende Spannung:" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "sigma[" << i+1 << "] = " << sigma[i] << endl;
	}
	
	return 0;
}					        // Funktionsende

void fkt_eingabe(float** feld, float* epsilon, int dimension)
{

	for(int i=0;i<dimension;i++)
		{
		cout << i+1 << ". Eintrag der Dehnungsmatrix eingeben!" << endl;	
		cin >> epsilon[i];	
		}

	for(int j=0;j<dimension;j++)
		{ cout << "Eintraege der " << j+1 << ". Zeile der Steifigkeitsmatrix." << endl;
		for(int k=0;k<dimension;k++)
			{
			cin >> feld[j][k];	
			}
			
		}
}

void fkt_berechnung(float** feld, float* sigma, float* epsilon, int dimension)
{
	for(int i=0;i<dimension;i++)
		{
		for(int j=0;j<dimension;j++)
			{
			sigma[i]+=(feld[i][j])*(epsilon[j]);
			}
		}
}

