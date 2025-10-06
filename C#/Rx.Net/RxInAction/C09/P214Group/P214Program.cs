using System.Reactive.Linq;
using Helpers;

namespace P214Group;

internal class P214Program
{
  static void Main(string[] args)
  {
    GroupByExample();
  }

  private static void GroupByExample()
  {
    var people = new List<Person>()
    {
      new(gender: Gender.Male, age: 21),
      new(gender: Gender.Female, age: 31),
      new(gender: Gender.Male, age: 23),
      new(gender: Gender.Female, age: 33)
    }.ToObservable();

    var grouped =
      from gender in people.GroupBy(p => p.Gender)
      from avg in gender.Average(p => p.Age)
      select new { Gender = gender.Key, AvgAge = avg };

    grouped.SubscribeConsole("Gender Age");

    Console.ReadLine();
  }
}

internal enum Gender
{
  Male,
  Female
}

internal class Person
{
  public Person(Gender gender, int age)
  {
    Gender = gender;
    Age = age;
  }

  public Gender Gender { get; set; }
  public int Age { get; set; }
}