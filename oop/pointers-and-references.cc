
// Based on "Stroustrup, Bjarne (2019). A Tour of C++. 2nd ed. Third
// printing. Addison-Wesley"
//
// and
//
// https://www.embedded.com/electronics-blogs/programming-pointers/4024641/An-Introduction-to-References

#include <iostream>

using namespace std;

//////////////////////////////////////////////////////////////////////////////
// Coping arrays

void
fn1 ()
{
  // Source array. In declarations, `[]` means "array of".
  int v1[10] = {0,1,2,3,4,5,6,7,8,9};

  // Target array.
  int v2[10];

  // Copying the arrays.
  for (int i = 0; i != 10; ++i)
    v2[i] = v1[i];

  // Print the target array.
  for (int i = 0; i != 10; ++i)
    cout << v2[i] << endl;
}

//////////////////////////////////////////////////////////////////////////////
// Pointers
//
// A pointer variable is a variable that stores/points the address of
// another variable of the appropriate type.

void
fn2 ()
{
  // Array of characters.
  char v[6] = "aeiou";

  // In declarations, `*` means "pointer to". The variable `p` is a
  // pointer to character.
  char* p;

  // In expressions, a prefix unary `&` means "address of". The
  // pointer `p` points to the third element of `v`.
  //
  // Make figure in the whiteboard.
  p = &v[2];
  cout << (void *) p << endl;

  // In expressions, a prefix unary `*` means "contents of". The
  // content of `p` is the third element of `v`.
  char x;

  x = *p;
  cout << x << endl;

  // What is the ouput of `p`?
  //
  // cout << p << endl;
  //
  // The reason for that is that `std::cout` will treat a `char*` as a
  // pointer to (the first character of) a C-style string and print it
  // as such. (from
  // https://stackoverflow.com/questions/17813423/cout-with-char-argument-prints-string-not-pointer-value)

  // What is the ouput of `p + 10`?
  //
  // cout << p + 10 << endl;
  //
  // Why?

  // What is the ouput of `(void *) (p + 10)`?
  //
  // cout << (void *) (p + 10) << endl;
  //
  // Why?
}

//////////////////////////////////////////////////////////////////////////////
// References

/*
"A reference is similar to a pointer, except that you don’t need to
use a prefix * to access the value referred to by the reference. Also,
a reference cannot be made to refer to a different object after its
initialization." (Stroustrup, 2019, p. 12)
*/

void
fn3 ()
{
  int i = 3;
  int* pi;

  pi = &i;

  // In a declaration, the unary suffix & means "reference to". The
  // variable `ri` is a reference to `int` referring the variable `i`.
  int& ri = i;

  cout << i << endl << *pi << endl << ri << endl;

  // Changes the value of `i` to `4`.
  *pi = 4;
  cout << i << endl;

  // Changes the value of `i` to `5`.
  ri = 5;
  cout << i << endl;

  // Pointer arithmetic.
  // pi++;
  // cout << (void *) pi << endl;

  // No reference arithmetic.
  // ri++;
  // cout << ri << endl;
}

//////////////////////////////////////////////////////////////////////////////
// Pointers and references as parameters

// Does not work because C++ passes function arguments by value.
void
swap1 (int v1, int v2)
{
  int temp = v1;

  v1 = v2;
  v2 = temp;
}

// Solution using pointers.
void
swap2 (int* v1, int* v2)
{
  int temp = *v1;

  *v1 = *v2;
  *v2 = temp;
}

// Solution using references.
void
swap3 (int& v1, int& v2)
{
  int temp = v1;

  v1 = v2;
  v2 = temp;
}

//////////////////////////////////////////////////////////////////////////////
// Main

int
main ()
{
  // fn1 ();
  // fn2 ();
  // fn3 ();

  int i = 10;
  int j = 20;

  // swap1 (i, j);
  // swap2 (&i, &j);
  swap3 (i, j);

  cout << "i = " << i << " and j = " << j << endl;
}
