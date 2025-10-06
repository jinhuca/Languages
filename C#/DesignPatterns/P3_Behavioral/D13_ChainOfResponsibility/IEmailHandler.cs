namespace D13_ChainOfResponsibility
{
  public interface IEmailHandler
  {
    IEmailHandler NextHandler { set; }
    void ProcessHandler(string email);
  }
}
