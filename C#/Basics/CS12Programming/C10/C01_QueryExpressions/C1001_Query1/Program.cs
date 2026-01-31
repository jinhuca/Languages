using System.Globalization;

IEnumerable<CultureInfo> commaCultures_ =
  from culture in CultureInfo.GetCultures(CultureTypes.AllCultures)
  where culture.NumberFormat.NumberDecimalSeparator == ","
  select culture;

foreach (var culture_ in commaCultures_) {
  Console.WriteLine(culture_.Name);
}