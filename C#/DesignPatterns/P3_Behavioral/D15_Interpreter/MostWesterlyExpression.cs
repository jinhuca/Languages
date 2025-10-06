using System.Collections.Generic;

namespace D15_Interpreter
{
  public class MostWesterlyExpression : IExpression
  {
    private IList<IExpression> expressions;

    public MostWesterlyExpression(IList<IExpression> expressions)
    {
      this.expressions = expressions;
    }

    public virtual City Interpret()
    {
      City resultingCity = new City("Nowhere", 999.9, 999.9);
      foreach (IExpression currentExpression in expressions)
      {
        City currentCity = currentExpression.Interpret();
        if (currentCity.Longitude < resultingCity.Longitude)
        {
          resultingCity = currentCity;
        }
      }
      return resultingCity;
    }

  }
}
