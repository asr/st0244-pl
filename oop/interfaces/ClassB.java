
public class ClassB extends SuperClass {

  @Override
  public void doSomething() {
    System.out.println("`doSomething` implementation of class `B`");
  }

  // ClassB specific method.
  public void methodB() {
  }

  public static void main(String[] args) {
    ClassB objB = new ClassB();

    objB.doSomething();
  }
}
