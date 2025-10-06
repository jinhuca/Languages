using static System.Console;

namespace D15_Interpreter
{
  public class Program
  {
    public static void Main(string[] args)
    {
      // Create the evaluator
      DirectionalEvaluator evaluator = new DirectionalEvaluator();

      // This should output "London"...
      WriteLine(evaluator.Evaluate("london edinburgh manchester southerly"));

      // This should output "Aberdeen"...
      WriteLine(evaluator.Evaluate("london edinburgh manchester southerly aberdeen westerly"));
    }
  }
}
