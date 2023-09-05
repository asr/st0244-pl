
public class ClassA extends SuperClass {

  @Override
  public void doSomething() {
    System.out.println("`doSomething` implementation of class `A`");
  }

  // ClassA own method.
  public void methodA() {
  }

  public static void main(String[] args) {
    ClassA objA = new ClassA();

    objA.doSomething();
  }
}
