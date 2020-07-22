
public class ClassCAdapter implements InterfaceC {

  @Override
  public void doSomething() {
    System.out.println("`doSomething' implementation of class `C`");
  }

  public static void main(String[] args) {
    ClassCAdapter objC = new ClassCAdapter();

    objC.doSomething();
  }
}
