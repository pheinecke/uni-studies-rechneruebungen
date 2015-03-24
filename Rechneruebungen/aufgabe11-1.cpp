#include <iostream>					// Praeprozessoranweisung

using namespace std;

// Klassendefinition:
class Moebel
{
	protected:
		double hoehe;
		double breite;
		double tiefe;
		char material[20];

	public:
	  void set_hoehe(double hoehe);
		void set_breite(double breite);
		void set_tiefe (double tiefe);
		void set_material (const char* material);
		double get_hoehe();
		double get_breite();
		double get_tiefe();
		char* get_material();
};

class Schrank:public Moebel
{
private:
	bool spiegel;
	int anz_tueren;
public:
	bool get_spiegel();
	int get_anz_tueren();
	void set_spiegel(bool);
	void set_anz_tueren(int);
	Schrank operator+(Schrank&);
};


// H A U P T F U N K T I O N
int main()
{
	// Ersten Schrank instanziieren
	Schrank erster_Schrank;
	erster_Schrank.set_hoehe(2.20);
	erster_Schrank.set_breite(1.50);
	erster_Schrank.set_tiefe(0.60);
	erster_Schrank.set_material("Holz");
	erster_Schrank.set_spiegel(true);
	erster_Schrank.set_anz_tueren(2);

	// Zweiten Schrank instanziieren
	Schrank zweiter_Schrank;
	zweiter_Schrank.set_hoehe(2.50);
	zweiter_Schrank.set_breite(1.00);
	zweiter_Schrank.set_tiefe(0.60);
	zweiter_Schrank.set_material("Holz");
	zweiter_Schrank.set_spiegel(false);
	zweiter_Schrank.set_anz_tueren(1);

	// Dritter Schrank: "Summe" der beiden ersten Schränke
	Schrank dritter_Schrank;
	dritter_Schrank=erster_Schrank+zweiter_Schrank;
	// (hier Aufruf des Additionsoperators einfuegen!)

	// Daten des dritten Schranks ausgeben:
	cout << "Daten des zusammengesetzten Schranks:" << endl;
	cout << " Hoehe:       " << dritter_Schrank.get_hoehe() << endl;
	cout << " Breite:      " << dritter_Schrank.get_breite() << endl;
	cout << " Tiefe:       " << dritter_Schrank.get_tiefe() << endl;
	cout << " Material:    " << dritter_Schrank.get_material() << endl;
	cout << " Spiegel:     " << dritter_Schrank.get_spiegel() << endl;
	cout << " Anz. Tueren: " << dritter_Schrank.get_anz_tueren() << endl;

	return 0;
}


// M E T H O D E N D E F I N I T I O N E N    D E R    B A S I S K L A S S E


void Moebel::set_hoehe(double hoehe)
{
	this->hoehe = hoehe;
}

double Moebel::get_breite()
{
	return this->breite;
}

void Moebel::set_breite(double breite)
{
	this->breite = breite;
}

void Moebel::set_tiefe(double tiefe)
{
	this->tiefe = tiefe;
}

void Moebel::set_material(const char* material)
{
	int len = 19;
	for (int i = 18; i >= 0; i--) {
		if (material[i] == '\0') len = i;
	}
	cout << "Laenge: " << len << endl << endl;
	for (int i = 0; i < len; i++) {
		this->material[i] = material[i];
	}
	this->material[len] = '\0';
}


double Moebel::get_hoehe()
{
	return hoehe;
}


double Moebel::get_tiefe()
{
	return tiefe;
}

char* Moebel::get_material()
{
	char* res = new char[20];
  for (int i = 0; i < 20; i++)
	{
		res[i] = material[i];
	}
	
	return res;
}

// M E T H O D E N D E F I N I T I O N E N    D E R    S U B K L A S S E
void Schrank::set_spiegel(bool spiegel)
{
	this->spiegel = spiegel;
}

void Schrank::set_anz_tueren(int anz_tueren)
{
	this->anz_tueren = anz_tueren;
}

bool Schrank::get_spiegel()
{
	return spiegel;
}

int Schrank::get_anz_tueren()
{
	return anz_tueren;
}

// Ueberladenen Additionsoperator hier einfuegen

Schrank Schrank::operator+(Schrank& summand)
{
	if(get_tiefe()==summand.get_tiefe())
	{
		Schrank Summe_Schrank;
		Summe_Schrank.set_tiefe(get_tiefe());
		Summe_Schrank.set_breite(get_breite()+summand.get_breite());
		Summe_Schrank.set_anz_tueren(get_anz_tueren()+summand.get_anz_tueren());
			if(get_hoehe()<=summand.get_hoehe()){
				Summe_Schrank.set_hoehe(summand.get_hoehe());
			}
			else{
				Summe_Schrank.set_hoehe(get_hoehe());
			}
		Summe_Schrank.set_material("mehrteilig");
		
		if(get_spiegel() or summand.get_spiegel()){
		Summe_Schrank.set_spiegel(true);	
		}
		else {Summe_Schrank.set_spiegel(false);}
		
		return Summe_Schrank;
	}
	else
	{	Schrank Summe_Schrank;
		return Summe_Schrank;
	}
}
