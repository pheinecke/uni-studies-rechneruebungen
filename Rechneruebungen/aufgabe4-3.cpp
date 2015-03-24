#include <iostream>

using namespace std;

int betrag(int);
float betrag(float);
double betrag(double);

int main()
{
	int zahl1;
	float zahl2;
	double zahl3;
	
	cout << "Geben Sie eine Ganzzahl ein: ";
	cin >> zahl1;
	cout << "Geben Sie eine Fliesskommazahl ein: ";
	cin >> zahl2;
	cout << "Geben Sie noch eine Fliesskommazahl ein: ";
	cin >> zahl3;

	cout << "Der Betrag der ersten  Zahl ist: " << betrag(zahl1) << endl;
	cout << "Der Betrag der zweiten Zahl ist: " << betrag(zahl2) << endl;
	cout << "Der Betrag der dritten Zahl ist: " << betrag(zahl3) << endl;
	
	return 0;
}

int betrag(int zahl)
{
	if(zahl<0)
	{return (zahl*(-1));}
	else {return zahl;}
}

float betrag(float zahl)
{
	if(zahl<0)
	{return (zahl*(-1));}
	else {return zahl;}
}

double betrag(double zahl)
{
	if(zahl<0)
	{return (zahl*(-1));}
	else {return zahl;}
}
