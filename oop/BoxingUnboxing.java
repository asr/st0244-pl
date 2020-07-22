
import java.util.ArrayList;

public class BoxingUnboxing {
  public static void main(String args[]) {

    ArrayList <Integer> intList = new ArrayList <>();
    int x = 6;
    int a, b;

    // Old way via wrapper and unwrapping.
    @SuppressWarnings("deprecation")
      Integer y = new Integer(x); // Wrapping
    intList.add(y);
    a = intList.get(0).intValue(); // Unwrapping
    System.out.println("Value via wrapper and unwrapping: " + a);

    // New way via auto-boxing and auto-unboxing.
    intList.add(x); // Auto-boxing
    b = intList.get(1); // Auto-unboxing.
    System.out.println("Value via auto-boxing and auto-unboxing: " + b);
  }
}
