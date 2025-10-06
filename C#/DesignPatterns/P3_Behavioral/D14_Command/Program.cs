using static System.Console;

namespace D14_Command
{
  public class Program
  {
    public static void Main(string[] args)
    {
      // Create a radio and its up/down command objects
      Radio radio = new Radio();
      radio.SwitchOn();
      IVoiceCommand volumeUpCommand = new VolumeUpCommand(radio);
      IVoiceCommand volumeDownCommand = new VolumeDownCommand(radio);

      // Create an electric window and its up/down command objects
      ElectricWindow window = new ElectricWindow();
      IVoiceCommand windowUpCommand = new WindowUpCommand(window);
      IVoiceCommand windowDownCommand = new WindowDownCommand(window);

      // Create a speech recogniser object
      SpeechRecognizer speechRecognizer = new SpeechRecognizer();
      speechRecognizer.SetCommands(volumeUpCommand, volumeDownCommand);
      WriteLine("Speech recognition controlling the radio");
      speechRecognizer.HearUpSpoken();
      speechRecognizer.HearUpSpoken();
      speechRecognizer.HearUpSpoken();
      speechRecognizer.HearDownSpoken();

      speechRecognizer.SetCommands(windowUpCommand, windowDownCommand);
      WriteLine("Speech recognition will now control the window");
      speechRecognizer.HearDownSpoken();
      speechRecognizer.HearUpSpoken();
    }
  }
}
