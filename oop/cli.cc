
#include <iostream>
#include <vector>

using namespace std;

// Main function with arguments.
// The first argument is the name of the program.
int main (int argc, char** argv)
{
  cout << "Number of arguments: " << argc << endl;

  // The argument zero is the name of the program.
  for ( int i = 0; i < argc; i++ )
    cout << argv[i] << endl;

  // Using a for-each loop.
  // vector<string> args(argv, argv + argc);
  // for (const auto& a : args)
  //   cout << a << endl;
}

// Running example:
// $ make cli
// ./cli c++ java haskell prolog
// Number of arguments: 5
// ./cli
// c++
// java
// haskell
// prolog
