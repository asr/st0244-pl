
public class Warning {
  public static void main(String args[]) {
    String s = (String) "hello, word";
    System.out.println(s);
  }
}

// Using -Xlint:
// $ javac -Xlint Warning.java
// Warning.java:4: warning: [cast] redundant cast to String
//     String s = (String)"hello, word!";
//                ^
// 1 warning

// Using -Xlint and -Werror:
// $ javac -Xlint -Werror Warning.java
// Warning.java:4: warning: [cast] redundant cast to String
//     String s = (String)"hello, word";
//                ^
// error: warnings found and -Werror specified
// 1 error
// 1 warning
