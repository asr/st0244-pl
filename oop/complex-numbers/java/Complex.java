// Adapted from:
// Kenneth C. Louden y Kenneth A. Lambert (2011). Programming
// Languages. Principles and Practice. 3rd ed. Cengage Learning.

public class Complex extends Object {

  // Instance variables
  private double re, im;

  // Default constructor
  public Complex() {
    this(0, 0);
  }

  // Parameterized constructor
  public Complex(double realPart, double imaginaryPart) {
    re = realPart;
    im = imaginaryPart;
  }

  public double realPart() {
    return re;
  }

  public double imaginaryPart() {
    return im;
  }


  public boolean equals(Complex c) {
    return (this.realPart() == c.realPart() &&
            this.imaginaryPart() == c.imaginaryPart());
  }

  public Complex add(Complex c) {
    return new Complex(this.realPart() + c.realPart(),
                       this.imaginaryPart() + c.imaginaryPart());
  }

  public Complex multiply(Complex c) {
    return new Complex(this.realPart() * c.realPart() -
                       this.imaginaryPart() * c.imaginaryPart(),
                       this.realPart() * c.imaginaryPart() +
                       this.imaginaryPart() * c.realPart());
  }

  public String toString() {
    return this.realPart() + "+" + this.imaginaryPart() + "i";
  }
}
