#include <iostream>

using namespace std;

void fktausg(int, double);

int main()
{
	int intwert=0;
	double doublewert=0.0;

	cout << "\nint Wert eingeben!" << endl;
	cin >> intwert;

	cout <<"\ndouble Wert eingeben!" << endl;
	cin >> doublewert;
	
	fktausg(intwert, doublewert);
return 0;	
}

void fktausg(int intwert, double doublewert)
{
	intwert=intwert;				//variable intwert bekommt übergegeben Wert zugewiesen
	doublewert=doublewert;			//variable doublewet bekommt übergegeben Wert zugewiesen
	
	int *intptr = NULL;			//Init. des Zeigers auf den Int-Wert
	double *doubleptr = NULL;	//Init. des Zeigers auf den double-Wert
	
	intptr = &intwert;			//Pointer bekommen Adresse der Variablen zugewiesen.
	doubleptr = &doublewert;
	
//1. Variante	
	cout << "\nint-Wert: " << intwert << "\nint-Speicheradresse: " << intptr << endl;
	cout << "\ndouble-Wert: " << doublewert << "\ndouble-Speicheradresse: " << doubleptr << endl;
//2. Variante
	cout << "\nint-Wert: " << intwert << "\nint-Speicheradresse: " << &intwert << endl;
	cout << "\ndouble-Wert: " << doublewert << "\ndouble-Speicheradresse: " << &doublewert << endl;
//3. Variante
	cout << "\nint-Wert: " << intwert << "\nint-Speicheradresse: " << intptr << "\nint-Pointer-Adr.: " << &intptr <<endl;
	cout << "\ndouble-Wert: " << doublewert << "\ndouble-Speicheradresse: " << doubleptr <<  "\ndouble-Pointer-Adr.: " << &doubleptr << endl;		
	
}