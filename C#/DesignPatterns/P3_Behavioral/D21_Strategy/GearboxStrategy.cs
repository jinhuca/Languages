namespace D21_Strategy
{
  public interface IGearboxStrategy
  {
    void EnsureCorrectGear(IEngine engine, int speed);
  }
}
