
#include <stdio.h>

// Possible error: body of constexpr function ‘constexpr double
// square(double)’ not a return-statement

constexpr int
square (int x)
{
  // printf ("%d\n", x)
  return x*x;
  // return (printf ("%d\n", x));
}

int
main ()
{
  printf ("%d\n", square (3));
}
