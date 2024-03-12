
#include <iostream>

using std::cout;
using std::endl;

class ClassA {
public:
  void doSomething() {
    cout << "`doSomething` method of `ClassA`" << endl;
  }
};

class ClassB : public ClassA {
public:
  void doSomething() {
    cout << "`doSomething` method of `ClassB`" << endl;
  }
};

class ClassC : public ClassA {
public:
  void doSomething() {
    cout << "`doSomething` method of `ClassC`" << endl;
  }
};

class ClassD : public ClassB, public ClassC {
  // If we remove the `doSomething()` method we got a compiler error:
  // request for member `doSomething` is ambiguous
public:
  void doSomething() {
    cout << "`doSomething` method of `ClassD`" << endl;
  }
};

int main()
{
  ClassA objA;
  ClassB objB;
  ClassC objC;
  ClassD objD;

  objA.doSomething();
  objB.doSomething();
  objC.doSomething();
  objD.doSomething();
}
