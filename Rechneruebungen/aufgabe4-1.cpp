#include<iostream>

using namespace std;

float func(float x1, float x2); //Deklaration

int main()
{
float x1,x2;
	
cout << "\nX1-Wert und X2-Wert nacheinander einegeben, jeweils mit Enter bestaetigen!" << endl;
cin >> x1;
cin >> x2;
cout << "\nErgebnis:" << func(x1,x2) << endl;
	
return 0;	
}

float func(float x1, float x2)
{
return ((x1*x1*x1)+7*x2);	
}


