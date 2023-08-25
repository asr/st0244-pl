// Adapted from "Stroustrup, Bjarne (2018). A Tour of C++. 2nd
// ed. Addison-Wesley".

// Vectores via structures.

#include <iostream>

using namespace std;

// The vector structure.
struct Vector {
  double* elem; // Pointer to elements.
  int sz;       // Number of elements.
};

// Construct a `Vector`.
void vectorInit(Vector& v, int s)
{
  // Allocate an array of `s` doubles.
  // The `new` operator allocates memory from the heap.
  v.elem = new double[s];
  v.sz = s;
}

// Example using `Vector`.
double readAndSum(int s)
// Read `s` integers from `cin` and return their sum; `s` is assumed
// to be positive.
{
  // A variable of type Vector.
  Vector v;

  // Allocate `s` elements for `v`.
  vectorInit(v, s);

  // Read into elements.
  for ( int i = 0; i != v.sz; ++i )
    cin >> v.elem[i];

  double sum = 0;

  // Compute the sum of the elements.
  for ( int i = 0; i != v.sz; ++i )
    sum += v.elem[i];

  return sum;
}

int main()
{
  double r = readAndSum(3);

  cout << "The sum (using structures) is " << r << endl ;
}
