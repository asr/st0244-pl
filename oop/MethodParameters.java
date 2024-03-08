class Person {
  private String name;
  private int age;

  Person(String n, int a) {
    name = n;
    age = a;
  }

  public int getAge() {
    return age;
  }

  public void setAge(int a) {
    age = a;
  }

  public String getName() {
    return name;
  }
}

public class MethodParameters {

  // Primitive parameter.
  public static void duplicateValue(int x) {
    x = x * 2;
    System.out.println("duplicateValue: x=" + x);
  }

  // Object reference.
  public static void duplicateAge(Person p) {
    int currentAge = p.getAge();
    p.setAge(currentAge * 2);
    System.out.println("duplicateAge: age=" + p.getAge());
  }

  public static void main(String[] args) {
    // Primitive parameter.
    int v1 = 10;

    duplicateValue(v1);
    // The value of `v1` did not change.
    System.out.println("v1="+ v1);

    // Object reference.
    Person p = new Person("Juan", 21);

    System.out.println("p: "+ p.getName() + ", " + p.getAge());
    duplicateAge(p);
    // The age of `p` was duplicated.
    System.out.println("p: "+ p.getName() + ", " + p.getAge());
  }
}
