#include "pet.h"

class Cat : public Pet
{
public:
  //constructor and destructor
  Cat(std::string name);
  void Climb();
  ~Cat();
};
