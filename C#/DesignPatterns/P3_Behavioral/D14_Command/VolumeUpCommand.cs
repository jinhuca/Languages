namespace D14_Command
{
  public class VolumeUpCommand : IVoiceCommand
  {
    private readonly Radio _radio;

    public VolumeUpCommand(Radio radio)
    {
      _radio = radio;
    }

    public virtual void Execute() => _radio.VolumeUp();
  }
}
