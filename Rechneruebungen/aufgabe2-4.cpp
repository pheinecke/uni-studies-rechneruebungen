// aufgabe2-4.cpp
#include <iostream>

using namespace std;

int main(void)                                                                      // Kopf Hauptprogramm
{
    char zeichen;                                                                   // Variablendefinition
    int zahl;

    zeichen = 'A';
    zahl = 5;
    
    // Operation 1
    zeichen = zeichen + 5;
    cout << "\nZEICHEN > " << zeichen << endl;                                    
    
    // Operation 2
    cout << "\nZAHL > " << zahl++ << endl;                                        
    
    // Operation 3
    zahl = 2;
    zahl--;
    cout << "\nZAHL > " << ++zahl << endl;                                          
    
    // Operation 4
    zeichen = ++zeichen - 7;
    cout << "\nZEICHEN > " << --zeichen ;                                   
    
    // Operation 5
    zahl = 10;
    zahl -= 5;
    zahl++;
    cout << "\nZAHL > " << zahl-- << endl;                         
    
	return 0;
}



