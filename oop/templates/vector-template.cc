// Adapted from "Stroustrup, Bjarne (2018). A Tour of C++. 2nd
// ed. Addison-Wesley".

// Vectores via classes.

#include <iostream>

using namespace std;

// "A template is a class or a function that we parameterize with a set
// of types or values. We use templates to represent ideas that are
// best understood as something general from which we can generate
// specific types and functions by specifying arguments, such as the
// vector’s element type double." (p.~79)

template<typename T>
class Vector {
private:
  T* elem; // `elem` points to an array of `sz` elements of type `T`.
  int sz;  // The number of elements.

public:
  // Constructor.
  Vector(int s) : elem {new T[s]}, sz {s} {}

  // Element access (subscripting).
  T& operator[](int i) { return elem[i]; }

  int size() const { return sz; }
};

// Example using `Vector`.
template<typename T>
T readAndSum (int s)
// Read `s` integers from `cin` and return their sum; `s` is assumed
// to be positive.
{
  // Make a vector of `s` elements.
  Vector<T> v(s);

  // Read into elements.
  for (int i = 0; i != v.size(); ++i)
    cin >> v[i];

  T sum = 0;

  // Compute the sum of the elements.
  for (int i = 0; i != v.size(); ++i)
    sum += v[i];

  return sum;
}

int
main ()
{
  int r = readAndSum<int> (3);

  cout << "The sum (using templates) is " << r << endl ;
}
