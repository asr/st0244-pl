
public class ClassD implements InterfaceA, InterfaceB, InterfaceC, InterfaceD
{
  public void doSomething() {
    System.out.println("`doSomething` implementation of `ClassD`");
  }

  public static void main(String[] args) {
    InterfaceD objD = new ClassD();

    objD.doSomething();
  }
}
