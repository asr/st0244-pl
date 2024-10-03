// The main.

class Main {
  public static void main(String[] args) {
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
