using static System.Console;

namespace D14_Command
{
  public class ElectricWindow
  {
    private bool _open;

    public ElectricWindow()
    {
      _open = false;
      WriteLine("Window is closed");
    }

    public virtual bool Open => _open;

    public virtual bool Closed => (!_open);

    public virtual void OpenWindow()
    {
      if (Closed)
      {
        _open = true;
        WriteLine("Window is now open");
      }
    }

    public virtual void CloseWindow()
    {
      if (Open)
      {
        _open = false;
        WriteLine("Window is now closed");
      }
    }
  }
}
