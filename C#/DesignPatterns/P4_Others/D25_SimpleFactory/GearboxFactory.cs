namespace D25_SimpleFactory
{
  public class GearboxFactory
  {
    public enum Type
    {
      Automatic, Manual
    }

    public static Gearbox Create(Type type)
    {
      return type == Type.Automatic ? (Gearbox) new AutomaticGearbox() : new ManualGearbox();
    }
  }
}
