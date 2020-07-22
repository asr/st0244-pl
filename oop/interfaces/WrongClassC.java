
public class WrongClassC extends ClassA {
// public class WrongClassC extends ClassA, ClassB {

  @Override
  public void doSomething() {
    System.out.println("`doSomething` implementation of class `WrongClassC`");
  }

  public static void main(String[] args) {
    WrongClassC objC = new WrongClassC();

    objC.doSomething();
  }
}
