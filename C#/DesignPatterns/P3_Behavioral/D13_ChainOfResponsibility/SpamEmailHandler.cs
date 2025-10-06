using static System.Console;

namespace D13_ChainOfResponsibility
{
  public class SpamEmailHandler : AbstractEmailHandler
  {
    protected internal override string[] MatchingWords() => new[] { "viagra", "pills", "medicines" };
    protected internal override void HandleHere(string email) => WriteLine("This is a spam email.");
  }
}
