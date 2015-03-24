#include<iostream>

using namespace std;

bool teilbar(int, int);

int main()
{
	int zahl, teiler;
	
	cout << "\nZahl eingeben" << endl;
	cin >> zahl; 
	
	while(zahl<0)
	{
	cout <<"\nZahl muss positiv sein. Eingabe wiederholen." << endl;
	cin >> zahl;
	}
	
	cout << "\nEingebene Zahl: " << zahl << endl;
	
	for(teiler=2;teiler<=10;teiler++)
	{
		if(teilbar(zahl,teiler)==1)
		{
		cout << zahl << " ist teilbar durch " << teiler << endl;
		}
		else
		{
		cout << zahl << " ist nicht teilbar durch " << teiler << endl;	
		}
	}
		
	
	
return 0;	
}

bool teilbar(int zahl, int teiler)
{
	if(zahl%teiler == 0)
	{return 1;}
	else
	{return 0;}
}