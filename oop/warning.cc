
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
  int i;
  cout << i << endl;
}

// Using -Wall:
// $ g++ -Wall warnings.cpp
// warnings.cpp: In function ‘int main(int, char**)’:
// warnings.cpp:10:11: warning: ‘i’ is used uninitialized in this function [-Wuninitialized]
//    cout << i << endl;
//            ^

// Using -Wall and -Werror:
// $ g++ -Wall -Werror warnings.cpp
// warnings.cpp: In function ‘int main(int, char**)’:
// warnings.cpp:10:11: error: ‘i’ is used uninitialized in this function [-Werror=uninitialized]
//    cout << i << endl;
//            ^
// cc1plus: all warnings being treated as errors
