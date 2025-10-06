using static System.Console;

namespace D13_ChainOfResponsibility
{
  class Program
  {
    static void Main(string[] args)
    {
      string email = "I need my car repaired";
      AbstractEmailHandler.Handle(email);
      Read();
    }
  }
}
