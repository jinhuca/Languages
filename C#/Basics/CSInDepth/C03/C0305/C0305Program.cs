namespace C0305;

internal class C0305Program
{
  static void Main(string[] args)
  {
    var player = new
    {
      Name = "Rajesh",
      Score = 3500
    };
    Console.WriteLine("Play name: {0}", player.Name);
    Console.WriteLine("Player score: {0}", player.Score);
  }
}