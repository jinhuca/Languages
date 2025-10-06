using System.Collections.Generic;

namespace D15_Interpreter
{
  public class MostNortherlyExpression : IExpression
  {
    private IList<IExpression> expressions;

    public MostNortherlyExpression(IList<IExpression> expressions)
    {
      this.expressions = expressions;
    }

    public virtual City Interpret()
    {
      City resultingCity = new City("Nowhere", -999.9, -999.9);
      foreach (IExpression currentExpression in expressions)
      {
        City currentCity = currentExpression.Interpret();
        if (currentCity.Latitude > resultingCity.Latitude)
        {
          resultingCity = currentCity;
        }
      }
      return resultingCity;
    }
  }
}
