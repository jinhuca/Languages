// GroupJoin: Groups two collections by a common key value, and is similar to left outer join in SQL.

using static System.Console;

class Language
{
  public int Id { get; set; }
  public string Name { get; set; }
}

class Person
{
  public int LanguageId { get; set; }
  public string FirstName { get; set; }
}

public class C033Program
{
  public static void Main()
  {
    Language[] languages_ =
    [
      new() { Id = 1, Name = "English" },
      new() { Id = 2, Name = "Russian" }
    ];

    Person[] persons_ =
    [
      new() { LanguageId = 1, FirstName = "Tom" },
      new() { LanguageId = 1, FirstName = "Sandy" },
      new() { LanguageId = 2, FirstName = "Vladimir" },
      new() { LanguageId = 2, FirstName = "Mikhail" }
    ];

    var result_ = languages_.GroupJoin(persons_, lang => lang.Id, pers => pers.LanguageId,
      (lang, ps) => new { key = lang.Name, Persons = ps });

    WriteLine("Group-joined list of people speaking either English or Russian:");
    foreach (var language in result_)
    {
      WriteLine($"Persons speaking {language.key}:");
      foreach (var person in language.Persons)
      {
        WriteLine(person.FirstName);
      }
    }
  }
}