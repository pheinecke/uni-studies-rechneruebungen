#include <iostream>					// Präprozessoranweisung

using namespace std;

void fkt_eingabe(float**, float*, int);                 // Funktionsprototypen
void fkt_berechnung(float**, float*, float*, int);


int main()						// Funktionskopf
{
	//Variablen
	const int dim = 3;
/*	float sigma[dim]={0.0}, epsilon[dim];									// Felddefinitionen
	float matrix[dim][dim]={0.0};
  float* feld[dim]={matrix[0], matrix[1], matrix[2]};*/
	
	float *sigma_ptr = NULL;
	float *epsilon_ptr = NULL;
	float **feld_ptr = NULL;
	
	sigma_ptr = new float[dim];
	epsilon_ptr = new float[dim];
	
	for(int i=0;i<dim;i++)
		{
		sigma_ptr[i]=0.0;
		epsilon_ptr[i]=0.0;
		}
		
	feld_ptr = new float*[dim];
	for(int i=0;i<dim;i++)
		{
			feld_ptr[i]=new float[dim];
		}
	
	for(int i=0;i<dim;i++)
		{
			for(int j=0;j<dim;j++)
				{
				feld_ptr[i][j] = 0.0;
				}
		}
	//Eingabe
  fkt_eingabe(feld_ptr, epsilon_ptr, dim);
	
	//Berechnung
	fkt_berechnung(feld_ptr, sigma_ptr, epsilon_ptr, dim);
	
	//Ausgabe
	cout << "Resultierende Spannung:" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "sigma[" << i+1 << "] = " << sigma_ptr[i] << endl;
	}
	
	delete [] sigma_ptr;
	sigma_ptr = NULL;
	
	delete [] epsilon_ptr;
	epsilon_ptr = NULL;
	
	for(int i=0;i<0;i++)
		{
		delete [] feld_ptr[i];
		feld_ptr[i] = NULL;
		}
	delete [] feld_ptr;
	feld_ptr = NULL;
		
	return 0;
}					        // Funktionsende


void fkt_eingabe(float **feld, float *epsilon, int dimension)
{
    //Eingabe
	cout << "Komponenten der Steifigkeitsmatrix eingeben:" << endl;
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			cout << "E[" << i+1 << "][" << j+1 << "]: ";
			cin >> feld[i][j];
		}
	}
	cout << "Komponenten der Dehnung eingeben:" << endl;
	for (int i = 0; i < dimension; i++)
	{
		cout << "epsilon[" << i+1 << "]: ";
		cin >> epsilon[i];
	}
    
    
}

void fkt_berechnung(float **feld, float *sigma, float *epsilon, int dimension)
{
    //Berechnung
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            sigma[i] += feld[i][j] * epsilon[j];
        }
    }
    
    
}



