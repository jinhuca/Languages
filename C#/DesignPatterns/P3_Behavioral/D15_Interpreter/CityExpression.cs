namespace D15_Interpreter
{
  public class CityExpression : IExpression
  {
    private City city;

    public CityExpression(City city)
    {
      this.city = city;
    }

    public virtual City Interpret()
    {
      return city;
    }
  }
}
