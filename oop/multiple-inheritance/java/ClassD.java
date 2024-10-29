
public class ClassD implements InterfaceB, InterfaceC, InterfaceD
{
  public void foo() {
    System.out.println("Implementation of the `foo()` method in `ClassD`");
  }

  public void bar() {
    System.out.println("Implementation of the `bar()` method in `ClassD`");
  }

  public static void main(String[] args) {
    InterfaceD objD = new ClassD();

    objD.foo();
    objD.bar();
  }
}
