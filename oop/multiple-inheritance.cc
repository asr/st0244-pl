
#include <iostream>
using std::cout;
using std::endl;

class SuperClass {
public:
  virtual void doSomething() = 0;
};

class ClassA : public SuperClass {
public:
  void doSomething() {
    cout << "`doSomething` method of `ClassA`" << endl;
  }
};

class ClassB : public SuperClass {
public:
  void doSomething() {
    cout << "`doSomething` method of `ClassB`" << endl;
  }
};

class ClassC : public ClassA, public ClassB {
public:
  void doSomething() {
    cout << "`doSomething` method of `ClassC`" << endl;
  }
};


int main()
{
  ClassA objA;
  ClassB objB;
  ClassC objC;

  objA.doSomething();
  objB.doSomething();
  objC.doSomething();
}
