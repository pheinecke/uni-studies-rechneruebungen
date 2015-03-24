#include <iostream>
using namespace std;

class Notenspgl { 
    private:
        // NICHTZEIGERATTRIBUTE
        int anz_faecher;
        char student[20];
        float schnitt;
        //ZEIGERATTRIBUTE
        float* noten;
        int* nummer;
    
    public:
        // METHODENDEFINITIONEN
        void setNote(int eintrag, int nummer, float note);
        void setNoten(int anz_faecher);
        void print();
        void calcSchnitt();

    
        // Definitionen zum Setzen des Namens > zwei Möglichkeiten > überladene Fuktion/Methode
        void setName(char* name);
        void setName();
    
        Notenspgl& operator=(const Notenspgl& orig);
        
};

// M E T H O D E N D E F I N I T I O N E N

Notenspgl& Notenspgl::operator=(const Notenspgl& orig){
	if(&orig!=this){
	this->anz_faecher=orig.anz_faecher;
	for(int i=0;i<20;i++)
		{this->student[i]=orig.student[i];}
	this->schnitt = orig.schnitt;
		
	delete [] this->noten;
	delete [] this->nummer;
		
	this->noten = new float[this->anz_faecher];
	this->nummer = new int[this->anz_faecher];
	
	for (int i=0; i<anz_faecher; i++){
	this->noten[i]=orig.noten[i];
	this->nummer[i]=orig.nummer[i];}
	}
	
return *this;
}

// Ausgabe des Notenspiegels auf den Bildschirm
void Notenspgl::print() {
    cout << "Student: " << this->student << endl;
    for (int i=0; i<this->anz_faecher; i++) {
        cout << "Fach: " << this->nummer[i] << " > Note: " << this->noten[i] << endl;
    }
    cout << "Notendurchschnitt: " << this->schnitt << endl;
}


// setzen einer Einzelnote
void Notenspgl::setNote(int eintrag, int nr, float note) {
    this->nummer[eintrag] = nr;
    this->noten[eintrag] = note;
    this->calcSchnitt();
}

// setzen einer bestimmten Anzahl von Noten
void Notenspgl::setNoten(int anz_faecher) {
    // Speicher anfordern, Einträge abfragen und zuweisen
    this->anz_faecher = anz_faecher;
    this->noten = new float[this->anz_faecher];
    this->nummer = new int[this->anz_faecher];
    for (int i=0; i<this->anz_faecher; i++) {
        cout << "Pruefungsnummer: ";
        cin >> this->nummer[i];
        cout << "Note: ";
        cin >> this->noten[i];
    }
    
    // Aufruf der Methode calcSchnitt() zur Berechnung des Notendurchschnitts
    this->calcSchnitt();
}

// Methode zur Berechnung der Durchschnittsnote
void Notenspgl::calcSchnitt() {
    float summe = 0;
    for (int i=0; i<anz_faecher; i++) {
        summe += this->noten[i];
    }
    this->schnitt = summe/anz_faecher;
}

// Methoden zum Setzen des Namens, 2fach > überladene Funktion
void Notenspgl::setName(char* name) {
    for (int i=0; i<20; i++) {
        this->student[i] = name[i];
    }
}
void Notenspgl::setName() {
    cout << "Name des Studenten: ";
    cin >> student;
}


// H A U P T P R O G R A M M
int main() {
    Notenspgl stud1;                    // Instanzierung eines Objekts > Student1
    stud1.setName();                    // Aufruf der Methode setName die vom Benutzer einen Namen fordert
    stud1.setNoten(2);                  // Aufruf von setNoten, die Übergabe von 2 fordert zur Eingabe von zwei Prüfungsnummern und Noten auf
    cout << endl;
    stud1.print();                      // Ausgabe des Notenspiegels, inklusive Durchschnittsnote
    cout << endl;
    
    Notenspgl stud2;                    // Instanzierung eines zweiten Objekts > Student2
    stud2 = stud1;                      // Zuweiung des ersten Objekts an das neue Objekt
    
    stud2.setName("Student2");          // Veränderung des Namens des NEUEN Objekts mit der überladenen Methode setName
    stud2.setNote(0, 123, 2.3);          // Änderung der beiden Noten mittels der Methode setNote des NEUEN Objekts
    stud2.setNote(1, 456, 1.3);
    
    stud1.print();                      // Kontrollausgabe beider Notenspiegel               
    cout << endl;
    stud2.print();

    return 0;
}
