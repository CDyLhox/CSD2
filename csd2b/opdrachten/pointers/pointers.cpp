#include <iostream>

/*
  Assignment: complete this program by putting your code in all the locations
    that say -- your code here --

  Make sure that the program compiles and builds and check the output
    after every change.

  Tip: before you look at the output, always think ahead what you expect to
    see and then check if your assumption was correct.
 */

int main()
{
    char letter = 97; // find this in the ASCII table (type 'man ascii') a
    char *letterpointer;

    std::cout << "\033[37m" << "Contents of the variable letter: ";
    // -- your code here --
    std::cout << "\033[35m" << letter << std::endl;

    letterpointer = &letter;
    std::cout << "\033[37m" << "Contents of letterpointer: ";
    // -- your code here --
    std::cout << "\033[35m" << letterpointer << std::endl;
    std::cout << "\033[37m" << "Contents of what letterpointer points to: ";
    // -- your code here --
    std::cout << "\033[35m" << *letterpointer << std::endl;

    *letterpointer = 'b';
    std::cout << "\033[37m" << "The variabele letter has gotten a new value through letterpointer.";
    std::cout << "\033[37m" << "Contents of what letterpointer points to: ";
    // -- your code here --
    std::cout << "\033[35m" << *letterpointer << std::endl;

    std::cout << "\033[37m" << "Contents of the variable letter: ";
    // -- your code here --
    std::cout << "\033[35m" << letter << std::endl;

    /*
     * Create the necessary pointer(s) and use them
     */

    unsigned short year = 2019;
    std::cout << "\033[37m" << "Contents of the variabele year: ";
    // -- your code here --
    std::cout << "\033[35m" << year << std::endl;

    // create a pointer to year
    // -- your code here --
    unsigned short *yearpointer;
    yearpointer = &year;
    // std::cout << "\033[35m" << year << std::endl;

    std::cout << "\033[37m" << "Contents of yearpointer: ";
    // -- your code here --
    std::cout << "\033[35m" << yearpointer << std::endl;

    std::cout << "\033[37m" << "Contents of what yearpointer points to: ";

    // give year a new value via yearpointer
    // -- your code here --
    std::cout << "\033[35m" << *yearpointer << std::endl;

    std::cout << "\033[37m" << "Contents of the variabele year: ";
    // -- your code here --
    std::cout << "\033[35m" << year << std::endl;

    // create another pointer to year, named anotheryearpointer
    // -- your code here --
    unsigned short *anotheryearpointer;
    anotheryearpointer = &year;

    std::cout << "\033[37m" << "Contents of anotheryearpointer: ";
    // -- your code here --
    std::cout << "\033[35m" << anotheryearpointer << std::endl;

    std::cout << "\033[37m" << "Contents of what anotheryearpointer points to: ";
    // -- your code here --
    std::cout << "\033[35m" << *anotheryearpointer << std::endl;

    // give year a new value via anotheryearpointer
    // -- your code here --
    *anotheryearpointer = 0111; // this is interesting cause i edited the short and the computer now reads the short as binary

    std::cout << "\033[37m" << "Contents of year: ";
    // -- your code here --
    std::cout << "\033[35m" << year << std::endl;

    std::cout << "\033[37m" << "Contents of what anotheryearpointer points to: ";
    // -- your code here --
    std::cout << "\033[35m" << *anotheryearpointer << std::endl;

    // anotheryearpointer++;
    *anotheryearpointer++;

    std::cout << "\033[37m" << "Contents of anotheryearpointer after ++: ";
    // -- your code here --
    std::cout << "\033[35m" << "i believe this to be vague frasing either that or im tired. \n im going to do both" << std::endl;
    std::cout << "\033[35m" << "while typing this next line of code i realise im tired anyways im still intrigued" << std::endl;
    std::cout << "\033[35m" << "contents of anotheryearpointer " << *anotheryearpointer << std::endl;
    anotheryearpointer++;
    std::cout << "\033[35m" << "contents of anotheryearpointer plus one " << anotheryearpointer << std::endl;

} // main()
