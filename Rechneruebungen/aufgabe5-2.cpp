#include <iostream>

using namespace std;

class artikel {
	private:
		int menge;
	public:
		void setzeMenge(int);
		int gibMenge(void);
	
};

void artikel::setzeMenge(int menge){
this->menge=menge;
}

int artikel::gibMenge(void){
return menge;	
}

int main(void){
	//Instanzierung
	artikel Zucker;
	artikel Mehl;
	
	int mengeZucker=0;
	int mengeMehl=0;
	
cout << "Menge Zucker?" << endl;
cin >> mengeZucker;
cout <<"Menge Mehl?" << endl;
cin >> mengeMehl;
	
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
	
cout << "Eingegebene Menge Zucker: " << Zucker.gibMenge() << endl;
cout << "Eingebebene Menge Mehl: " << Mehl.gibMenge() << endl;		
return 0;	
}