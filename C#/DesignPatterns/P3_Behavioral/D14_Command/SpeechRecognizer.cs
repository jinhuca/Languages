namespace D14_Command
{
  public class SpeechRecognizer
  {
    private IVoiceCommand _upCommand, _downCommand;

    public virtual void SetCommands(IVoiceCommand upCommand, IVoiceCommand downCommand)
    {
      _upCommand = upCommand;
      _downCommand = downCommand;
    }

    public virtual void HearUpSpoken()
    {
      _upCommand.Execute();
    }

    public virtual void HearDownSpoken()
    {
      _downCommand.Execute();
    }
  }
}
