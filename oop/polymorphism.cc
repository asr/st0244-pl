
// Adapted from https://catonmat.net/cpp-polymorphism.

#include <iostream>

using std::cout;

class Felid {
public:
  // Pure virtual function. Derived classes need to override/implement
  // the function.
  virtual void meow() = 0;
};

class Cat : public Felid {
public:
  void meow() { cout << "Meowing like a regular cat! meow!\n"; }
};

class Tiger : public Felid {
public:
  void meow() { cout << "Meowing like a tiger! MREOWWW!\n"; }
};

class Ocelot : public Felid {
public:
  void meow() { cout << "Meowing like an ocelot! mews!\n"; }
};

class OtherFelid : public Felid {};

void do_meowing(Felid& felid)
{
  felid.meow();
}

int main()
{
  Cat    cat;
  Tiger  tiger;
  Ocelot ocelot;
  // OtherFelid otherFelid;

  do_meowing(cat);
  do_meowing(tiger);
  do_meowing(ocelot);
  // do_meowing(otherFelid);
}
