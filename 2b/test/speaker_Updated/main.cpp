#include <iostream>

// ========== TWEETER STUFF ==========

class Tweeter
{
public:
  // default constructor
  Tweeter();
  // overloaded constructor
  Tweeter(float diam);

  // fields
  float diameter;
  float conePosition;
};

Tweeter::Tweeter()
{
  std::cout << "Tweeter - default constructor\n";
  // NOTE: duplicate code alarm!!
  // constructor delegation is a better strategy!

  // in cm
  diameter = 2.5f;
  // number with an f --> indicate it is a float
  conePosition = 0.0f;
}

Tweeter::Tweeter(float diam)
{
  std::cout << "Tweeter - constructor with float diam parameter\n";
  // in cm
  diameter = diam;
  // number with an f --> indicate it is a float
  conePosition = 0.0f;
}

// =========== WOOF WOOOF WOOOF WOOOF WOOOF ===========
// ░░░░░░░░░▄░░░░░░░░░░░░░░▄░░░░
// ░░░░░░░░▌▒█░░░░░░░░░░░▄▀▒▌░░░
// ░░░░░░░░▌▒▒█░░░░░░░░▄▀▒▒▒▐░░░
// ░░░░░░░▐▄▀▒▒▀▀▀▀▄▄▄▀▒▒▒▒▒▐░░░
// ░░░░░▄▄▀▒░▒▒▒▒▒▒▒▒▒█▒▒▄█▒▐░░░
// ░░░▄▀▒▒▒░░░▒▒▒░░░▒▒▒▀██▀▒▌░░░
// ░░▐▒▒▒▄▄▒▒▒▒░░░▒▒▒▒▒▒▒▀▄▒▒▌░░
// ░░▌░░▌█▀▒▒▒▒▒▄▀█▄▒▒▒▒▒▒▒█▒▐░░
// ░▐░░░▒▒▒▒▒▒▒▒▌██▀▒▒░░░▒▒▒▀▄▌░
// ░▌░▒▄██▄▒▒▒▒▒▒▒▒▒░░░░░░▒▒▒▒▌░
// ▐▒▀▐▄█▄█▌▄░▀▒▒░░░░░░░░░░▒▒▒▐░
// ▐▒▒▐▀▐▀▒░▄▄▒▄▒▒▒▒▒▒░▒░▒░▒▒▒▒▌
// ▐▒▒▒▀▀▄▄▒▒▒▄▒▒▒▒▒▒▒▒░▒░▒░▒▒▐░
// ░▌▒▒▒▒▒▒▀▀▀▒▒▒▒▒▒░▒░▒░▒░▒▒▒▌░
// ░▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▒░▒░▒▒▄▒▒▐░░
// ░░▀▄▒▒▒▒▒▒▒▒▒▒▒░▒░▒░▒▄▒▒▒▒▌░░
// ░░░░▀▄▒▒▒▒▒▒▒▒▒▒▄▄▄▀▒▒▒▒▄▀░░░
// ░░░░░░▀▄▄▄▄▄▄▀▀▀▒▒▒▒▒▄▄▀░░░░░
// ░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▀▀░░░░░░░░

class Woofer
{
public:
  // default constructor
  Woofer();

  Woofer(float Wdiam);

  // Woofer aWoofer
  float Wdiameter;
  float WconePosition;

  // std::cout << "Woofer - consstructor\n";
};

Woofer::Woofer()
{
  std::cout << "A woofer or bass speaker is a technical term for a loudspeaker driver designed to produce low frequency sounds, typically from 20 Hz up to a few hundred Hz. The name is from the onomatopoeic English word for a dog's deep bark, 'woof'." << std::endl;

  Wdiameter = 10.0f;
  WconePosition = 0.0f;
}

Woofer::Woofer(float Wdiam)
{
  std::cout << "i dont understand why you would want to change this but not actually give me the option to change anything.." << std::endl;

  Wdiameter = Wdiam;
  WconePosition = 0.0f;
}
// TODO - add woofer

class Speaker
{
public:
  Speaker();

  Tweeter aTweeter;
  Woofer aWoofer;
};

Speaker::Speaker()
{
  // float userdiam;
  // std::cin >> userdiam;

  std::cout << "Speaker - constructor\n";
  aTweeter.diameter = 2.4;
  aWoofer.Wdiameter = 2.5;

  std::cout << "The diameter of the tweeter is: "
            << aTweeter.diameter << "\n";

  std::cout << "the diameter of the Woofer is: " 
  << aWoofer.Wdiameter << "\n";
}

int main()
{
  Speaker aSpeaker;
  return (0);
};
