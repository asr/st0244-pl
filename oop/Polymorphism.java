
// Adapted from https://catonmat.net/cpp-polymorphism.

// Abstract class and method.
//
// An abstract cannot be used to create objects.
//
// The body of an abstract method must be provided by the subclass.
abstract class Felid {
  public abstract void meow();
}

class Cat extends Felid {
  public void meow() {
    System.out.print("Meowing like a cat! meow!\n");
  }
}

class Tiger extends Felid {
  public void meow() {
    System.out.print("Meowing like a tiger! MREOWWW!\n");
  }
}

// Error: OtherFelid is not abstract and does not override abstract
// method meow() in Felid
//
// class OtherFelid extends Felid {};

public class Polymorphism {

  public static void doMeowing(Felid felid) {
    felid.meow();
  }

  public static void main(String[] args) {
    Cat cat = new Cat();
    Tiger tiger = new Tiger();

    doMeowing(cat);
    doMeowing(tiger);
  }
}
