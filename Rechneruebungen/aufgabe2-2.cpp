#include <iostream>

using namespace std;

int main()
{
double zahl1,zahl2,zahl3,zahl4,mittelwert;
cout << "\nVier Zahlen eingeben, jeweils mit Enter bestaetigen.\n";
cin >> zahl1;
cin >> zahl2;
cin >> zahl3;
cin >> zahl4;

mittelwert = (zahl1+zahl2+zahl3+zahl4)/4;

cout << "\nDer Mittelwert betraegt:" << mittelwert << endl;

return 0;
}


