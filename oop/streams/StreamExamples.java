
import java.util.*;
import java.util.stream.*;

public class StreamExamples {
  static public void main(String[] args){

    //////////////////////////////////////////////////////////////////////////
    // Streams

    // Stream<T> represents a sequence of elements of type T.

    List<Integer> intList     = Arrays.asList(1, 4, 9, 16);
    Stream<Integer> intStream = intList.stream();

    String[] stringArray        = new String[] {"a", "b", "c"};
    Stream<String> stringStream = Arrays.stream(stringArray);

    //////////////////////////////////////////////////////////////////////////
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
    Set<String> s1 = new HashSet<String>();
    s1.add("ABC");
    s1.add("AbC");
    s1.add("abc");
    System.out.println(s1);

    Set<String> s2 = s1.stream()
      .map(String::toLowerCase)
      .collect(Collectors.toSet());

    System.out.println(s2);

    // Fith example
    Set<String> s3 = new TreeSet<String>();
    s3.add("ABC");
    s3.add("AbC");
    s3.add("abc");
    System.out.println(s3);

    TreeSet<String> s4 = s3.stream()
      .map(String::toUpperCase)
      .collect(Collectors.toCollection(TreeSet::new));

    System.out.println(s4);

    //////////////////////////////////////////////////////////////////////////
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
