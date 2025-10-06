Panda p1 = new Panda("Pan Dee");
Panda p2 = new Panda("Pan Dah");

Console.WriteLine(p1.Name);
Console.WriteLine(p2.Name);
Console.WriteLine(Panda.Population);

public class Panda
{
  public string Name;
  public static int Population;

  public Panda(string n)
  {
    Name = n;
    Population = Population + 1;
  }
}