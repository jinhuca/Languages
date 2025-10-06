using static System.Console;

namespace D14_Command
{
  public class Radio
  {
    public const int MinVolume = 0;
    public const int MaxVolume = 10;
    public const int DefaultVolume = 5;

    private bool switchedOn;
    private int volume;

    public Radio()
    {
      switchedOn = false;
      volume = DefaultVolume;
    }

    public virtual bool On => switchedOn;

    public virtual int Volume => volume;

    public virtual void SwitchOn()
    {
      switchedOn = true;
      WriteLine($"Radio now on, volume level {Volume}");
    }

    public virtual void SwitchOff()
    {
      switchedOn = false;
      WriteLine("Radio now off");
    }

    public virtual void VolumeUp()
    {
      if (On && Volume < MaxVolume)
      {
        volume++;
        WriteLine($"Volume turned up to level {Volume}");
      }
    }

    public virtual void VolumeDown()
    {
      if (On && Volume > MinVolume)
      {
        volume--;
        WriteLine($"Volume turned down to level {Volume}");
      }
    }
  }
}
