namespace D14_Command
{
  public class WindowDownCommand : IVoiceCommand
  {
    private readonly ElectricWindow _window;

    public WindowDownCommand(ElectricWindow window)
    {
      _window = window;
    }

    public virtual void Execute()
    {
      _window.OpenWindow();
    }
  }
}
