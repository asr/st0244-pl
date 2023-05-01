
public class CLI
{
// Main function with arguments.
// The first argument not is the name of the program.
  public static void main (String[] args)
  {
    System.out.println ("Number of arguments: " + args.length);

    // for ( int i = 0; i < args.length; i++ )
    //  System.out.println (args[i]);

    for (String s: args)
      System.out.println(s);
  }
}

// Runing example:
// $ java CLI c++ java haskell prolog
// Number of arguments: 4
// c++
// java
// haskell
// prolog
