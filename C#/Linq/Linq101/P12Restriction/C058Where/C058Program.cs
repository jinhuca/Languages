// Where: Filters elements from a collection to satisfy a specified condition.

using static System.Console;

Person[] persons =
[
  new() { Name = "Mike", Age = 25 },
  new() { Name = "Joe", Age = 43 },
  new() { Name = "Nadia", Age = 31 }
];

var result = persons.Where(p => p.Age >= 30);

WriteLine("Finding persons who are 30 years old or older:");
foreach(Person person in result)
  WriteLine($"{person.Name}: {person.Age} years old");

class Person
{
  public string Name { get; set; }
  public int Age { get; set; }
}