// Equality and Comparison Operators

using System.Text;

{
  // == and != test for equality and inequality of any type, but always return a bool value
  // (unless overloaded otherwise). Value types typically have a very simple notion of equality:
  int x = 1;
  int y = 2;
  int z = 1;

  Console.WriteLine(x == y);    // False
  Console.WriteLine(x != y);    // True
  Console.WriteLine(x == z);    // True

  Console.WriteLine(x < y);     // True
  Console.WriteLine(x >= z);    // True
}

// Equality with Reference Types
{
  // For reference types, equality, by default, is based on reference, as opposed to the actual
  // value of the underlying object.
  Dude d1 = new Dude("John");
  Dude d2 = new Dude("John");
  Console.WriteLine(d1 == d2);    // False
  Dude d3 = d1;
  Console.WriteLine(d1 == d3);    // True
}

// And & Or Operators
{
  // The && and || operators test for and and or conditions.
  Console.WriteLine(UseUmbrella(true, false, false));     // True
  Console.WriteLine(UseUmbrella(true, true, true));       // False

  bool UseUmbrella(bool rainy, bool sunny, bool windy) => !windy && (rainy || sunny);
}

// Short-circuiting
{
  StringBuilder sb = null;
  if (sb != null && sb.Length > 0)
    Console.WriteLine("sb has data");
  else
    Console.WriteLine("sb is null or empty");
}

// And & Or Operators - non-short-circuiting
{
  // Same examples as before, but with & and | instead of && and ||.
  // The results are identical, but without short-circuiting:

  Console.WriteLine(UseUmbrella(true, false, false));     // True
  Console.WriteLine(UseUmbrella(true, true, true));       // False
  
  StringBuilder sb = null;

  if (sb != null & sb.Length > 0)       // Exception is thrown!
    Console.WriteLine("sb has data");
  else
    Console.WriteLine("sb is null or empty");

  bool UseUmbrella(bool rainy, bool sunny, bool windy)
  {
    return !windy & (rainy | sunny);
  }
}

// Conditional operator (ternary)
{
  // The conditional operator (also called the ternary operator) has the form
  //    q ? a : b
  // where if condition q is true, a is evaluated, else b is evaluated.

  Console.WriteLine(Max(2, 3));
  Console.WriteLine(Max(3, 2));

  int Max(int a, int b) => (a > b) ? a : b;
}

public class Dude
{
  public string Name;
  public Dude(string n) { Name = n; }
}