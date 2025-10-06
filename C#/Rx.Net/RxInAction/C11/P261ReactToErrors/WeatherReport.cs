using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P261ReactToErrors;

internal class WeatherReport
{
  public double Temperature { get; set; }
  public string Station { get; set; }

  public override string ToString()
  {
    return string.Format("Station: {0}, Temperature: {1}", Station, Temperature);
  }
}

internal class WeatherSimulation
{
}