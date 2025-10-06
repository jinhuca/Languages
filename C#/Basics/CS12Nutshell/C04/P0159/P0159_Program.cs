namespace P0159;

delegate int Transformer(int x);            // 1. Declare delegate type

internal class P0159Program
{
  static void Main(string[] args)
  {
    int Square(int x) => x * x;             // 2. Create compatible method
    Transformer t = Square;                 // 3. Create delegate instance
    int answer = t(3);                      // 4. Invoke delegate instance
    Console.WriteLine(answer);
  }
}