
// Adapted from "Stroustrup, Bjarne (2019). A Tour of C++. 2nd
// ed. Third printing. Addison-Wesley".

// The class `Vector`

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
  Vector(int s) {

    // The size of the vector is an invariante
    if (s < 0)
      throw length_error{"Vector constructor: negative size"};

    // The `new` operator allocates memory from the heap.
    elem = new double[s];
    sz = s;

    // Initialize elements.
    for ( int i = 0; i != s; i++ )
      elem[i] = 0;
  }

  // Constructor. Initialisation from a list.
  Vector(std::initializer_list<double> lst) {

    // initialize with a list
    elem = new double[lst.size()];
    sz   = static_cast <int> (lst.size());

    // Copy from `lst` into `elem`.
    copy(lst.begin(), lst.end(), elem);
  }

  // Destructor.
  ~Vector() { delete[] elem; }

  // Element access (subscripting).
  double& operator[] (int i) { return elem[i]; }

  // The function does not modify the caller object so we use the
  // `const`.
  int size() const { return sz; }
};

// Example using `Vector`.
double read_and_sum(int s)
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
  for ( int i = 0; i != v.size(); ++i )
    sum += v[i];

  return sum;
}

void print_vector(Vector& v)
{
  for ( int i = 0; i != v.size(); ++i )
    cout << v[i] << endl;
}

int main()
{
  // Initialisation by giving the size.
  // Vector v1(3);

  // v1[0] = 1.0;
  // v1[1] = 2.0;
  // v1[2] = 3.0;

  // print_vector (v1);

  // Using vectors.
  // double r = read_and_sum (3);
  // cout << "The sum is: " << r << endl ;

  // The size of the vector is an invariante.
  // Vector v(-2);

  // Initialisation from a list.
  // Vector v2 = {1.0, 2.0, 3.0};

  // print_vector (v2);

  return 0;
}
