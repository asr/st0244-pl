// Toy home-finance accounting system based on the Smalltalk tutorial
// (https://www.gnu.org/software/smalltalk/manual/html_node/Tutorial.html).

#include <cstdlib>
#include <iostream>
#include <map>

// using namespace std;

using std::cin;
using std::cerr;
using std::cout;
using std::endl;

//////////////////////////////////////////////////////////////////////////////
// The `Account` class.

class Account {
private:          // Access specifier.
  float balance;  // Attribute.

public:  // Access specifier.
  // The constructor initializes the private variable `balance` to
  // zero.
  Account() { balance = 0.0; }

  // Pretty printer for the class.
  void prettyPrint() {
    cout << "The balance is " << balance;
  }

  // Deposit money.
  void deposit(float amount) {
    balance = balance + amount;
  }

  // Spend money.
  void spend(float amount) {
    balance = balance - amount;
  }
};

//////////////////////////////////////////////////////////////////////////////
// The `Savings` subclass.

// The `Savings` class is a subclass of the `Account` class.  It holds
// money, just like an `Account`, and it also pays interest based on
// its balance.

class Savings : public Account {
private:           // Access specifier.
  float interest;  // Attribute.

public:  // Access specifier.
  // The constructor initializes the private variable `interest`
  // to zero.
  Savings() { interest = 0.0; }

  // Pretty printer for the class.
  void prettyPrint() {
    // Calls the `prettyPrint` method of the superclass.
    Account::prettyPrint();
    cout << " and the interest is " << interest;
  }

  // Method.
  void newInterest(float amount) {
    // We add the `amount` to our interest.
    interest = interest + amount;

    // We add the `amount` to our balance.
    //
    // In a member function, the keyword `this` points to the object
    // for which the member function is called.
    this -> deposit(amount);
  }

  // Method.
  float clearInterest() {
    float oldInterest = interest;
    interest = 0.0;

    return oldInterest;
  }
};

//////////////////////////////////////////////////////////////////////////////
// The `Cheking` subclass.

// In the `Checking` subclass we keep track of two facts:
//
// * What check number we are on
//
// * How many checks we have left in our checkbook

class Checking : public Account {
private:                         // Access specifier.
  int checkNum, checksLeft;      // Attributes.
  std::map<int, float> history;  // Attribute.

public:  // Access specifier.
  // The constructor initializes the private variable `checksLeft` to
  // zero.
  Checking() { checksLeft = 0; }

  // Pretty printer for the class.
  void prettyPrint() {
    Account::prettyPrint();
    cout << ", the checks left are " << checksLeft
         << " and the checks written are " << history.size();
  }

  // `newChecks' fills our checkbook with checks.  We record what
  // check number we're starting with, and update the count of the
  // number of checks in the checkbook.
  void newChecks(int number, int checkCount) {
    checkNum = number;
    checksLeft = checkCount;
  }

  int writeCheck(float amount);

  void prettyPrintChecks();
};

// `writeCheck` notes the next check number, then bumps up the check
// number, and down the check count and use the `spend` method from
// the base class.
int Checking::writeCheck(float amount)
{
  int num;

  // Sanity check that we have checks left in our checkbook.
  if (checksLeft < 1) {

    // We write to the standard error.
    cerr << "Error: Out of checks" << endl;

    // We exit with an error.
    exit(1);
  }

  // Make sure we've never used this check number before.
  num = checkNum;
  if ( history.find(num) != history.end() ) {

    // We write to the standard error.
    cerr << "Error: Duplicate check number" << endl;

    // We exit with an error.
    exit(1);
  }

  // Record the check number and amount.
  history.insert({num, amount});

  // Update our next checknumber, checks left, and balance.
  checkNum = checkNum + 1;
  checksLeft = checksLeft - 1;

  // In a member function, the keyword `this` points to the object
  // for which the member function is called.
  this -> spend(amount);

  return num;
}

// Pretty print for checks.
void Checking::prettyPrintChecks()
{
  for (auto elem : history) {
    cout << "check number: "
         << elem.first
         << " value: "
         << elem.second
         << endl;
  }
}

//////////////////////////////////////////////////////////////////////////////
// The main.

int main()
{
  ////////////////////////////////////////////////////////////////////////////
  Account a;

  a.deposit(125);
  a.deposit(20);
  a.spend(10);

  a.prettyPrint();
  cout << endl;

  ////////////////////////////////////////////////////////////////////////////
  Savings s;

  s.deposit(125);
  s.deposit(20);
  s.spend(10);
  s.newInterest(5);

  s.prettyPrint();
  cout << endl;

  ////////////////////////////////////////////////////////////////////////////
  Checking c;

  c.deposit(250);
  c.newChecks(100,50);
  c.writeCheck(32);

  c.prettyPrint();
  cout << endl;

  c.prettyPrintChecks();
  cout << endl;

  ////////////////////////////////////////////////////////////////////////////
  return 0;
}
