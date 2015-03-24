#include <iostream>

using namespace std;

class artikel {
	
	public:
		int menge;	
};

int main() {
	artikel Zucker;
	artikel Mehl;
	
	cin >> Zucker.menge;
	cin >> Mehl.menge;
	
	cout << "Zucker: " << Zucker.menge << endl;
	cout << "Mehl: " << Mehl.menge << endl;

return 0;	
}