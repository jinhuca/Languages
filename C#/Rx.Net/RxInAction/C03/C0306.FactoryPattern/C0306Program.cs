namespace C0306.FactoryPattern;

internal class C0306Program
{
  static void Main()
  {
  }
}

class HeavyClass
{
  // This is a heavy class that takes long time to create
}

class ThinClass
{
  private HeavyClass _heavy;

  public HeavyClass Heavy => _heavy ??= new HeavyClass();

  public void SomeMethod()
  {
    var myHeavy = Heavy;
  }
}

class ClassWithLazy
{
	readonly Lazy<HeavyClass> _lazyHeavyClass = new(() =>
  {
    var heavy = new HeavyClass();
    return heavy;
  });

  public void SomeMethod()
  {
    var myHeavy = _lazyHeavyClass.Value;
  }
}