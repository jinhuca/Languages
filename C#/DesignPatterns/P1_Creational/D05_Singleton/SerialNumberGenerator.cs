namespace D05Singleton
{
  public class SerialNumberGenerator
  {
    private static SerialNumberGenerator _instance;
    public static SerialNumberGenerator Instance => _instance ??= new SerialNumberGenerator();

    private int _count;
    private SerialNumberGenerator(){}
    public virtual int NextSerial => ++_count;
  }
}
