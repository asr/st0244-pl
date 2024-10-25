
public class CLI {
// Main function with arguments.
//
// The first argument is not the name of the program.
  public static void main(String[] args) {

    System.out.println("Number of arguments: " + args.length);

    if (args.length == 0) {
      System.err.println("Error: Missing arguments");
      System.exit(1);
    }

    // Printing the arguments in the same order.
    // for ( int i = 0; i < args.length; i++ )
    //  System.out.println(args[i]);

    // System.out.println();

    // Using a for-each loop.
    // for (String s: args)
    //   System.out.println(s);

    // System.out.println();

    // Printing the arguments in reverse order.
    System.out.println("The arguments in reverse order were:");
    for ( int i = args.length - 1; i >= 0 ; i-- )
     System.out.println(args[i]);
  }
}

// Running example:
// $ javac CLI
// $ java CLI a1 b1 c1
// Number of arguments: 3
// The arguments in reverse order were
// c1
// b1
// a1
