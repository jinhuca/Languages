using static System.Console;

// Join: Joins two collections by a common key value, and is similar to inner join in SQL.

string[] warmCountries_ = { "Turkey", "Italy", "Spain", "Saudi Arabia", "Ethiopia" };
string[] europeanCountries_ = { "Denmark", "Germany", "Italy", "Portugal", "Spain" };

var result_ = warmCountries_.Join(europeanCountries_, warm => warm, european => european, (warm, european) => warm);

WriteLine("Joined countries which are both warm and European:");
foreach(string country_ in result_)
  WriteLine(country_);
