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
  public void prettyPrint() {
    super.prettyPrint();
    System.out.print(" and the interest is " + interest);
  }

  // Method.
  public void newInterest(float amount) {
    // We add the `amount` to our interest.
    interest = interest + amount;

    // We add the `amount` to our balance.
    super.deposit(amount);
  }

  // Method.
  float clearInterest() {
    float oldInterest = interest;
    interest = 0.0f;

    return oldInterest;
  }
};
