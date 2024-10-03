import java.util.HashMap;

// The `Cheking` subclass.

// In the `Checking` subclass we keep track of two facts:
//
// * What check number we are on
//
// * How many checks we have left in our checkbook

class Checking extends Account {
  private int checkNum, checksLeft;  // Attributes.
  HashMap<Integer, Float> history;  // Attributes.

  // The constructor initializes the private variable `checksLeft` to
  // zero and the private variable `history`.
  public Checking() {
    checksLeft = 0;
    history = new HashMap<Integer, Float>();
  }

  // Pretty printer for class.
  public void prettyPrint() {
    super.prettyPrint();
    System.out.print(", the checks left are " + checksLeft);
    System.out.print(" and the checks written are " + history.size());
  }

  // `newChecks' fills our checkbook with checks.  We record what
  // check number we're starting with, and update the count of the
  // number of checks in the checkbook.
  public void newChecks(int number, int checkCount) {
    checkNum = number;
    checksLeft = checkCount;
  }

  // `writeCheck` notes the next check number, then bumps up the check
  // number, and down the check count and use the `spend` method from
  // the base class.
  public int writeCheck(float amount) {
    int num;

    // Sanity check that we have checks left in our checkbook.
    if (checksLeft < 1) {

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

  public void prettyPrintChecks() {
    for ( Integer i : history.keySet() )
      System.out.println("check number: " + i + " value: " + history.get(i));
  }
}
