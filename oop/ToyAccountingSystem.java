
// Toy home-finance accounting system based on the Smalltalk tutorial
// (https://www.gnu.org/software/smalltalk/manual/html_node/Tutorial.html).

import java.util.HashMap;

//////////////////////////////////////////////////////////////////////////////
// The `Account` class.

class Account {
  private float balance;  // Attribute.

  // The constructor initializes the private variable `balance` to
  // zero.
  public Account() { balance = 0.0f; }

  // Pretty printer for class.
  public void prettyPrint()
  {
    System.out.print("The balance is " + balance);
  }

  // Deposit money.
  public void deposit(float amount)
  {
    balance = balance + amount;
  }

  // Spend money.
  public void spend(float amount)
  {
    balance = balance - amount;
  }
}

//////////////////////////////////////////////////////////////////////////////
// The `Savings` subclass.

// The `Savings` class is a subclass of the `Account` class.  It holds
// money, just like an `Account`, and it also pays interest based on
// its balance.

class Savings extends Account {
  private float interest;  // Attribute.

  // The constructor initializes the private variable `interest` to
  // zero.
  public Savings() { interest = 0.0f; }

  // Pretty printer for class.
  public void prettyPrint()
  {
    super.prettyPrint();
    System.out.print(" and the interest is " + interest);
  }

  // Method.
  public void newInterest(float amount)
  {
    // We add the `amount` to our interest.
    interest = interest + amount;

    // We add the `amount` to our balance.
    super.deposit(amount);
  }

  // Method.
  float clearInterest()
  {
    float oldInterest = interest;
    interest = 0.0f;

    return oldInterest;
  }
};

//////////////////////////////////////////////////////////////////////////////
// The `Cheking` subclass.

// In the `Checking` subclass we keep track of two facets:
//
// * What check number we are on
//
// * How many checks we have left in our checkbook

class Checking extends Account {
  private int checkNum, checksLeft;  // Attributes.
  HashMap<Integer, Float> history;  // Attributes.

  // The constructor initializes the private variable `checksLeft` to
  // zero and the private variable `history`.
  public Checking()
  { checksLeft = 0;
    history = new HashMap<Integer, Float>();
  }

  // Pretty printer for class.
  public void prettyPrint()
  {
    super.prettyPrint();
    System.out.print(", the checks left are " + checksLeft);
    System.out.print(" and the checks written are " + history.size());
  }

  // `newChecks' fills our checkbook with checks.  We record what
  // check number we're starting with, and update the count of the
  // number of checks in the checkbook.
  public void newChecks(int number, int checkCount)
  {
    checkNum = number;
    checksLeft = checkCount;
  }

  // `writeCheck` notes the next check number, then bumps up the check
  // number, and down the check count and use the `spend` method from
  // the base class.
  public int writeCheck(float amount)
  {
    int num;

    // Sanity check that we have checks left in our checkbook.
    if ( checksLeft < 1 ) {

      // We write to the standard error.
      System.err.println("Error: Out of checks");

      // We exit with an error.
      System.exit(1);
    }

    // Make sure we've never used this check number before.
    num = checkNum;
    if ( history.containsKey(num) ) {

      // We write to the standard error.
      System.err.println("Error: Duplicate check number");

      // We exit with an error.
      System.exit(1);
    }

    // Record the check number and amount.
    history.put(num, amount);

    // Update our next checknumber, checks left, and balance.
    checkNum = checkNum + 1;
    checksLeft = checksLeft - 1;
    super.spend(amount);

    return num;
  }

  public void prettyPrintChecks()
  {
    for ( Integer i : history.keySet() )
      System.out.println("check number: " + i + " value: " + history.get(i));
  }
}

//////////////////////////////////////////////////////////////////////////////
// The main.

class ToyAccountingSystem {
  public static void main(String[] args)
  {
    //////////////////////////////////////////////////////////////////////////
    Account a = new Account();

    a.deposit(125);
    a.deposit(20);
    a.spend(10);

    a.prettyPrint();
    System.out.println();

  ////////////////////////////////////////////////////////////////////////////
  Savings s = new Savings();

  s.deposit(125);
  s.deposit(20);
  s.spend(10);
  s.newInterest(5);

  s.prettyPrint();
  System.out.println();

  ////////////////////////////////////////////////////////////////////////////
  Checking c = new Checking();

  c.deposit(250);
  c.newChecks(100,50);
  c.writeCheck(32);

  c.prettyPrint();
  System.out.println();

  c.prettyPrintChecks();
  System.out.println();
  }
}
