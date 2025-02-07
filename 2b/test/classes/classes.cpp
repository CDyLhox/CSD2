
#include <iostream>

using namespace std; // nu hoef je dit niet meer te typen in de rest van de code.

/*
 * class stappenplan
 * 1. define the class
 * 2. define the constructor
 * 3. implement the constructor
 * 4. add fields/ methods (and define the methods) 
 */




// class definitie
class Note{
	public:
		// default constructor 
		Note(); //same name as class name (a function allocation)
		//initianiseren
		//
		void play(); // void ---> no return
		int getVelocity(); // int ---> returns an int
		//methods(a method is a function in a class a member of a class)
		//
		//fields ( a field is a member of a class)
		int midiNoteValue;
};

//functie 
Note::Note(){ // note :: Note ( in de class note heb je de functie note )
	std::cout << "note - constructor\n";
	midiNoteValue = 0; // hier kan je je variabelen netjes initialiseren.
}

void Note::play(){
	std::cout << "PLAYING NOTE: " <<midiNoteValue << std::endl;
}

int Note::getVelocity(){
	return velocity;
}

int main() {
	Note aNote;

std:cout << "aNote.midiNoteValue contains: "
	    << aNote.midiNoteValue << "\n";
}

