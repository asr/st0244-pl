// Adapted from:
// Kenneth C. Louden y Kenneth A. Lambert (2011). Programming
// Languages. Principles and Practice. 3rd ed. Cengage Learning.

public class TestComplex {
  public static void main(String[] args) {
    Complex c1 = new Complex(3.5, 4.6);
    Complex c2 = new Complex(2.0, 2.0);

    System.out.println(c1.equals(c2));

    Complex sum = c1.add(c2);
    System.out.println(sum);
  }
}
