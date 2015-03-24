#include <iostream>

using namespace std;

class artikel {
	private:
		int menge;
	public:
		void setzeMenge(int);
		int gibMenge(void);
		void verkaufeMenge(int);
		
	
};

void artikel::setzeMenge(int menge){
this->menge=menge;
}

int artikel::gibMenge(void){
return menge;	
}

void artikel::verkaufeMenge(int menge){
	if(this->menge==0)
	{
	cout << "\nEs konnte nichts verkauft werden!" << endl;	
	}
	else if(this->menge>0 && this->menge<menge)
	{
		cout << "\nEs konnte nur folgende Menge verkauft werden:" << this->menge << endl;
		this->menge=0;
	}
	else if(this->menge>menge)
	{
		cout << "\nVerkaufte Menge: " << menge << endl;
		this->menge -= menge;
	}


	
}

int main(void){
	//Instanzierung
	artikel Zucker;
	artikel Mehl;
	
	int mengeZucker=0;
	int mengeMehl=0;

//Eingabe Ausgangsmengen	
cout << "Menge Zucker?" << endl;
cin >> mengeZucker;
cout <<"Menge Mehl?" << endl;
cin >> mengeMehl;

//Falls negativ Werte auf 0 setzen	
if(mengeZucker>0){
	Zucker.setzeMenge(mengeZucker);
	}
	else {
		Zucker.setzeMenge(0);
		}
		
if(mengeMehl>0){
	Mehl.setzeMenge(mengeMehl);
	}
	else {
		Mehl.setzeMenge(0);
		}
//Ausgabe der eingebenen Daten		
cout << "\n-----------------------------------------" << endl;	
cout << "Eingegebene Menge Zucker: " << Zucker.gibMenge() << endl;
cout << "Eingebebene Menge Mehl: " << Mehl.gibMenge() << endl;
cout << "-----------------------------------------" << endl;			

//Abfrage zu verkaufende Menge Mehl		
cout << "\nMenge zu verkaufendes Mehl?" << endl;
cin >> mengeMehl;
		
Mehl.verkaufeMenge(mengeMehl);	


		
return 0;	
}