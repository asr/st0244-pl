// The `Account` class.

class Account {
  private float balance;  // Attribute.

  // The constructor initializes the private variable `balance` to
  // zero.
  public Account() { balance = 0.0f; }

  // Pretty printer for class.
  public void prettyPrint() {
    System.out.print("The balance is " + balance);
  }

  // Deposit money.
  public void deposit(float amount) {
    balance = balance + amount;
  }

  // Spend money.
  public void spend(float amount) {
    balance = balance - amount;
  }
}
