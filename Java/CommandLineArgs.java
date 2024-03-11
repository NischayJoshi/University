// Define a public class named CommandLineArgs
public class CommandLineArgs {

  // Define a public static method named main, which serves as the entry point of
  // the program
  // It takes an array of strings as input arguments from the command line
  public static void main(String args[]) {
    // Loop iterates throughout the args array
    for (int i = 0; i < args.length; i++) {
      // Printing each input argument individually followed by a space
      System.out.print(args[i] + " ");
    }
  }

} // End of the class CommandLineArgs
