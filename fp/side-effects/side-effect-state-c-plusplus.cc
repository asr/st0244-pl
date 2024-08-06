
#include <iostream>

// State (global variable)
int s = 0;

// The function `f` changes the state, i.e. the global variable.
int f(int a)
{
  s = 2;
  return a;
}

// The function `g` depends of the state, i.e. of the global variable.
int g(int b)
{
  return s + b;
}

int main()
{
  // The expressions `f(3) + g(4)` and `g(4) + f(3)` are not equals.
  std::cout << g(4) + f(3) << std::endl;
  std::cout << f(3) + g(4) << std::endl;

  return 0;
}
