using System.Reactive.Linq;
using System.Reactive.Subjects;
using Helpers;
using static System.Console;

namespace P197Aggregate;

internal class P197Program
{
  static void Main()
  {
    //SumExample1();
    //SumExample2();
    //CountExample1();
    //CountExample2();
    //AverageExample1();
    //MaxMinExample1();
    //MaxMinExample2();
    //MaxByExample1();
    //AggregateExample();
    //ScanExample();
    AggregateCustomExample();
  }

  static void SumExample1()
  {
    var subscription_ = Observable
      .Range(1, 5)
      .Sum()
      .Subscribe(WriteLine);
    ReadLine();
    subscription_.Dispose();
  }

  static void SumExample2()
  {
    var subscription_ = new Student[] {
      new Student { Name = "A", Grade = 88.7 },
      new Student { Name = "B", Grade = 90.3 },
      new Student { Name = "C", Grade = 79.6 }
    }
      .ToObservable()
      .Sum(s => s.Grade)
      .Subscribe(WriteLine);
    ReadLine();
    subscription_.Dispose();
  }

  static void CountExample1()
  {
    var subscription_ = Observable
      .Range(1, 5)
      .Count()
      .Subscribe(WriteLine);
    ReadLine();
    subscription_.Dispose();
  }

  static void CountExample2()
  {
    var subscription_ = Observable
      .Range(1, 5)
      .Count(x => x % 2 == 0)
      .Subscribe(WriteLine);
    ReadLine();
    subscription_.Dispose();
  }

  static void AverageExample1()
  {
    var subscription_ = Observable
      .Range(1, 5)
      .Average()
      .Subscribe(WriteLine);
    ReadLine();
    subscription_.Dispose();
  }

  static void MaxMinExample1()
  {
    var sub1_ = Observable
      .Range(1, 5)
      .Max()
      .SubscribeConsole("Max");
    var sub2_ = Observable
      .Range(1, 5)
      .Min()
      .SubscribeConsole("Min");
    ReadLine();
    sub1_.Dispose();
    sub2_.Dispose();
  }

  static void MaxMinExample2()
  {
    var sub1_ = new Student[]
    {
      new() { Name = "A", Grade = 89.3},
      new() { Name = "B", Grade = 99.2},
      new() { Name = "C", Grade = 92.7}
    }
      .ToObservable()
      .Max(s => s.Grade)
      .Subscribe(WriteLine);
    ReadLine();
    sub1_.Dispose();
  }

  static void MaxByExample1()
  {
    var sub1_ = new Student[]
      {
        new() { Name = "A", Grade = 89.3 },
        new() { Name = "B", Grade = 99.2 },
        new() { Name = "C", Grade = 92.7 }
      }
      .ToObservable()
      .MaxBy(s => s.Grade)
      .SelectMany(max => max)
      .SubscribeConsole("MaxBy");
    ReadLine();
    sub1_.Dispose();
  }

  static void AggregateExample()
  {
    Observable
      .Range(1, 5)
      .Aggregate(1, (accumulate, currItem) => accumulate * currItem)
      .SubscribeConsole("Aggregate");
  }

  static void ScanExample()
  {
    Observable
      .Range(1, 5)
      .Scan(1, (accumulate, currItem) => accumulate * currItem)
      .SubscribeConsole("Scan");
  }

  static void AggregateCustomExample()
  {
    Subject<int> numbers = new Subject<int>();
    numbers.Aggregate(
        new SortedSet<int>(),
        (largest, item) =>
        {
          largest.Add(item);
          if (largest.Count > 2)
          {
            largest.Remove(largest.First());
          }

          return largest;
        },
        largest => largest.FirstOrDefault())
      .SubscribeConsole();
    numbers.OnNext(3);
    numbers.OnNext(1);
    numbers.OnNext(4);
    numbers.OnNext(2);
    numbers.OnCompleted();
    ReadLine();
    numbers.Dispose();
  }
}

public class Student
{
  public string Name { get; set; }
  public double Grade { get; set; }
  public override string ToString() => $"Name = {Name}, Grade = {Grade}";
}