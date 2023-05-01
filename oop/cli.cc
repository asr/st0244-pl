#include <iostream>

using namespace std;

// Main function with arguments.
// The first argument is the name of the program.
int
main (int argc, char** argv)
{
  cout << "Number of arguments: " << argc << endl;

  // The argument zero is the name of the program.
  for (int i = 0; i < argc; i++)
    cout << argv[i] << endl;

  return 0;
}

// Runing example:
// Number of arguments: 5
// ./cli
// c++
// java
// haskell
// prolog
