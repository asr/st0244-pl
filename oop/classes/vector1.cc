// Adapted from "Stroustrup, Bjarne (2019). A Tour of C++. 2nd
// ed. Third printing. Addison-Wesley".

// Fisrt version of the class `Vector`.

#include <iostream>

using namespace std;

// Using classes for defining a type we can separate the interface to
// the type (public members) from its implementation/representation
// (private members.)

class Vector {
private:
  double* elem; // Pointer to the elements.
  int sz;       // The number of elements.

public:
  // Constructor.
  // The `new` operator allocates memory from the heap.
  Vector (int s) {
    elem = new double[s];
    sz = s;
  }

  // Element access (subscripting).
  double& operator[] (int i) { return elem[i]; }

  // Vector size.
  int size () { return sz; }
};

// Example using `Vector`.
double
readAndSum (int s)
// Read `s` integers from `cin` and return their sum; `s` is assumed
// to be positive.
{
  // Make a vector of `s` elements.
  Vector v(s);

  // Read into elements.
  for (int i = 0; i != v.size(); ++i)
    cin >> v[i];

  double sum = 0;

  // Compute the sum of the elements.
  for (int i = 0; i != v.size(); ++i)
    sum += v[i];

  return sum;
}

int
main ()
{
  double r = readAndSum (3);
  cout << "The sum is: " << r << endl ;

  return 0;
}
