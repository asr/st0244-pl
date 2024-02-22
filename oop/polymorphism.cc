
// Adapted from https://catonmat.net/cpp-polymorphism.

#include <iostream>

using std::cout;

class Felid {
public:
  // Pure virtual function.
  //
  // Derived classes need to override/implement the function.
  virtual void meow() = 0;
};

class Cat : public Felid {
public:
  void meow() { cout << "Meowing like a cat! meow!\n"; }
};

class Tiger : public Felid {
public:
  void meow() { cout << "Meowing like a tiger! MREOWWW!\n"; }
};

class OtherFelid : public Felid {};

void doMeowing(Felid& felid)
{
  felid.meow();
}

int main()
{
  Cat    cat;
  Tiger  tiger;

  // Error: cannot declare variable ‘otherFelid’ to be of abstract
  // type ‘OtherFelid’
  ///
  // OtherFelid otherFelid;

  doMeowing(cat);
  doMeowing(tiger);
}
