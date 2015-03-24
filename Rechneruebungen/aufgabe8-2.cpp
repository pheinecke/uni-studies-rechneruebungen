#include <iostream>					// Präprozessoranweisung

using namespace std;

// Klassendefinition der Klasse Rationale_Zahl:
class Rationale_Zahl
{
	private:
		int zaehler;
		int nenner;
	
	public:
		void set_zaehler(int);
		void set_nenner(int);
		int get_zaehler();
		int get_nenner();
		void print();
};

// Methodendefinitionen der Klasse Rationale_Zahl:
void Rationale_Zahl::set_zaehler(int wert)
{
	zaehler = wert;
}

void Rationale_Zahl::set_nenner(int wert)
{
	nenner = wert;
}

int Rationale_Zahl::get_zaehler()
{
	return zaehler;
}

int Rationale_Zahl::get_nenner()
{
	return nenner;
}

void Rationale_Zahl::print()
{
	cout << zaehler << "/" << nenner <<;
}


// Klassendefinition der Klasse Messung
class Messung
{
	private:
		Rationale_Zahl messwerte[3];
	
	public:
		void messwerte_einlesen();
	  void messwerte_ausgeben();
};

void Messung::messwerte_einlesen()
{
int temp1=0;
int temp2=0;
	
	for(int i=0;i<=2;i++)
		{
		cout << i+1 << ". Messwert: Zaehler eingeben!" << endl;
		cin >> temp1;
		cout << i+1 << ". Messwert: Nenner eingeben!" << endl;
		cin >> temp2;
		
			this->messwerte[i].set_zaehler(temp1);
			
			this->messwerte[i].set_nenner(temp2);
		
		}
}

void Messung::messwerte_ausgeben()
{
	for(int i=0;i<=2;i++)
		{
		this->messwerte[i].print();	
		}
	
}


int main()						// Funktionskopf
{

	Messung* messptr1 = new Messung;
	
	messptr1->messwerte_einlesen();
	messptr1->messwerte_ausgeben();

	

	delete messptr1;
	
	return 0;
}
