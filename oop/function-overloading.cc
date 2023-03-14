
// From: Wikipedia (2019-09-27)
// https://en.wikipedia.org/wiki/Function_overloading

#include <iostream>

using std::cout;
using std::endl;

// Volume of a cube.
int
volume (int s)
{
  return s * s * s;
}

// Volume of a cylinder.
double
volume (double r, int h)
{
  return 3.1415926 * r * r * h;
}

// Volume of a cuboid.
long
volume (long l, int b, int h)
{
  return l * b * h;
}

int
main ()
{
  cout << volume (10)            << endl;
  cout << volume (2.5, 8)        << endl;
  cout << volume (10, 100, 1000) << endl;
}
