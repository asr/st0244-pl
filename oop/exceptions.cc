
// Adapted from "Stroustrup, Bjarne (2019). A Tour of C++. 2nd
// ed. Third printing. Addison-Wesley".

#include <iostream>
using namespace std;

class Vector {
public:
  // Construct a Vector.
  Vector(int s) : elem {new double[s]}, sz {s} {}

  // Element access (subscripting).
  // double& operator[] (int i) { return elem[i]; }

  // Element access (subscripting). Detects an out-of-range access and
  // generates an exception.
  double& operator[] (int i)
  {
    if ( i < 0 || size () <= i )
      throw out_of_range {"Vector::operator[]"};
    return elem[i];
  }

  int size() const { return sz; }

private:
  double* elem; // Pointer to the elements.
  int sz;       // The number of elements.

};

int main()
{
  Vector v(2);

  v[0] = 10;
  v[1] = 20;

  // Using the vector without caching exceptions.
  // cout << "The size of vector is " << v.size() << endl ;
  // cout << "v[0] is " << v[0] << endl ;
  // cout << "v[0] is " << v[42] << endl ;

  // Using the vector caching exceptions.
  try
    {
      // Exceptions here are handled by the handler defined below.
      cout << "v[0] is " << v[0] << endl ;
      cout << "v[0] is " << v[42] << endl;
    }
  catch (out_of_range& err)
    {
      // oops: out_of_range error
      // ... handle range error ...
      cerr << "Exception on " << err.what() << endl;
    }

  cout << "Note that execution continues...\n";

  return 0;
}
