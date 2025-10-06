using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Reactive.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Module.Infrastructure.Units;

[TestClass]
public class NotificationTests
{
  [TestMethod]
  public void NotificationNamedPropertyTests()
  {
    Person p1_ = new Person();

    IObservable<string> expected_ = p1_.OnPropertyChanges(x => x.Name);

    List<string> expected2_ = new();
    expected_.Subscribe(x => expected2_.Add(x));

    p1_.Name = "Jane";
    p1_.Age = 23;

    Assert.IsTrue(expected2_.Count == 1);
  }

  [TestMethod]
  public void NotificationAnyPropertyTests()
  {
    Person p1_ = new Person();
    IObservable<Person> expected_ = p1_.OnAnyPropertyChanges();
  }
}

public class Person : BindableBase
{
  private string _name;
  public string Name
  {
    get => _name;
    set => SetProperty(ref _name, value);
  }

  private int _age;
  public int Age
  {
    get => _age;
    set => SetProperty(ref _age, value);
  }
}