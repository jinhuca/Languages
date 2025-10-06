using System.Reactive.Linq;

object value = new Person { Name = "Kinga" };
var source = Observable.Return(new object())
  .Concat(Observable.Return(value))
  .OfType<Person>()
  .Select(p => p.Name)
  .Subscribe(Console.WriteLine);

Console.ReadLine();

public class Person
{
  public string Name { get; set; }
}