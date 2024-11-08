
import java.util.*;
import java.util.stream.*;

public class TestStream {
  static public void main(String[] args){
    // Streams

    // Stream<T> represents a sequence of elements of type T.

   List<Integer> intList     = Arrays.asList(1, 4, 9, 16);
   Stream<Integer> intStream = intList.stream();

   String[] stringArray        = new String[] {"a", "b", "c"};
   Stream<String> stringStream = Arrays.stream(stringArray);

   // Map

   // First example
   List<Integer>   a = Arrays.asList(1, 4, 9, 16);
   Stream<Integer> b = intList.stream();
   Stream<Double>  c = b.map(x -> Math.sqrt(x));
   List<Double>    d = c.toList();

   System.out.println(d);

   // Second example
   List<Double> l2 = Arrays.asList(1, 4, 9, 16).stream()
     .map(x -> Math.sqrt(x))
     .toList();

   System.out.println(l2);

   // Third example
   List<Double> l3 = Arrays.asList(1, 4, 9, 16).stream()
     .map(Math::sqrt)
     .toList();

   System.out.println(l3);

   // Fourth example
   List<String> l4 = Arrays.asList("ABC", "AbC", "abc").stream()
     .map(String::toLowerCase)
     .toList();

   System.out.println(l4);

   // Filter

   // First example
   List<Character> l5 = Arrays.asList('S', 'T', '0', '2', '4', '4').stream()
     .filter(Character::isLetter)
     .toList();

   System.out.println(l5);

   // Second example
   List<String> l6 = Arrays.asList("c", "c++", "java").stream()
     .filter(s -> s.length() >= 4)
     .toList();

   System.out.println(l6);
  }
}
