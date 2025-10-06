// Select: Selects, projects and transforms elements in a collection.

using static System.Console;

double[] angles_ = [30D, 60D, 90D]; // Angles in radians

var result_ = angles_.Select(a => new { Angle = a, Cos = Math.Cos(a), Sin = Math.Sin(a) });

WriteLine("Calculated values:");
foreach(var res_ in result_)
  WriteLine($"Angle {res_.Angle}: Cos = {res_.Cos}, Sin = {res_.Sin}");
