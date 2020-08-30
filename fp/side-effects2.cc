
// From p. 229 of Kent D. Lee (2017), Foundations of Programming
// Languages, 2nd ed.

#include <iostream>

using namespace std;

int
main ()
{
  int x = 1;

  // Compile-time (using `-Wall`): Generates the follwing the warning:
  //
  // "operation on ‘x’ may be undefined [-Wsequence-point]"
  //
  // Run-time: Prints 1,2
  cout << x++ << "," << x << endl;
}
