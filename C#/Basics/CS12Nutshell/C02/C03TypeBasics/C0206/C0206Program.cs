// Predefined Type Examples

using System.Security.Cryptography.X509Certificates;

{
  string message = "Hello world";
  string upperMessage = message.ToUpper();
  Console.WriteLine(upperMessage);

  int x = 2022;
  message = message + x.ToString();
  Console.WriteLine(message);

  bool simpleVar = false;
  if(simpleVar)
    Console.WriteLine("This will not print.");

  int y = 5000;
  bool lessThanAMile = y < 5280;
  if (lessThanAMile) 
    Console.WriteLine("This will print");
}

// Custom Type Examples
{
  // Just as we can build complex functions from simple functions, we can build complex types from
  // primitive types. UnitConverter serves a blueprint for unit conversions:
  UnitConverter feetToInchesConverter = new UnitConverter(12);
  UnitConverter milesToFeetConverter = new UnitConverter(5280);

  Console.WriteLine(feetToInchesConverter.Convert(30));
  Console.WriteLine(feetToInchesConverter.Convert(100));
  Console.WriteLine(feetToInchesConverter.Convert(milesToFeetConverter.Convert(1)));
}

// Instance vs Static Members
{
  // The instance field Name pertains to an instance of a particular Panda,
  // whereas Population pertains to the set of all Pandas:
  Panda p1 = new Panda("Pan Dee");
  Panda p2 = new Panda("Pan Dah");
  Console.WriteLine(p1.Name);
  Console.WriteLine(p2.Name);
  Console.WriteLine(Panda.Population);
}

public class UnitConverter
{
  private int ratio;                                              // Field
  public UnitConverter(int unitRatio) { ratio = unitRatio; }      // Constructor
  public int Convert(int unit) { return ratio * unit; }           // Method
}

public class Panda
{
  public string Name;                 // Instance field
  public static int Population;       // Static field

  public Panda(string n)
  {
    Name = n;
    Population = Population + 1;
  }
}