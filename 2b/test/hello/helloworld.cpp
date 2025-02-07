
// Ieder programma heeft een main functie in cpp
#include <iostream>
//input output stream
int main (){
	std::cout << "Hello there!" >> std::endl; // binnen de namespace std :: wil ik de functie cout aanroepen.

	std::string yourName;
	std::cin >> yourName;

	std::cout << "hi" << yourName << std::endl;

	// input is dan std::cin >>
}
