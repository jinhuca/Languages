namespace D14_Command
{
  public class WindowUpCommand : IVoiceCommand
  {
    private readonly ElectricWindow _window;

    public WindowUpCommand(ElectricWindow window)
    {
      _window = window;
    }

    public virtual void Execute()
    {
      _window.CloseWindow();
    }
  }
}
