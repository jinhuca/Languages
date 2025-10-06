namespace D14_Command
{
  public class VolumeDownCommand : IVoiceCommand
  {
    private readonly Radio _radio;

    public VolumeDownCommand(Radio radio)
    {
      _radio = radio;
    }

    public virtual void Execute()
    {
      _radio.VolumeDown();
    }
  }
}
