
// From p. 229 of Kent D. Lee (2017), Foundations of Programming
// Languages, 2nd ed.

#include <iostream>

using namespace std;

int
main()
{
  int x = 1;

  // Compilation with `-Wall` generates the following the warning:
  //
  // "operation on ‘x’ may be undefined [-Wsequence-point]"
  //
  // The program prints `1,2`.
  cout << x++ << "," << x << endl;

  return 0;
}
