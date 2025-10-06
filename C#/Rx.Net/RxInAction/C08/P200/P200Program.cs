using System.Reactive.Linq;
using System.Reactive.Subjects;
using Helpers;

namespace P200;

internal class StudentGrade
{
  public StudentGrade(string id, string name, float grade)
  {
    Id = id;
    Name = name;
    Grade = grade;
  }

  public StudentGrade()
  {
  }

  public string Id { get; set; }
  public string Name { get; set; }
  public float Grade { get; set; }

  public override string ToString()
  {
    return "ID = " + Id + ", " + "Name = " + Name + ", Grade = " + Grade;
  }
}

internal class P200Program
{
  static void Main(string[] args)
  {
    FindMaxItems();
    AggregateCustomized();
    ScanCustomized();
  }

  static void FindMaxItems()
  {
    Subject<StudentGrade> grades = new Subject<StudentGrade>();
    grades.MaxBy(s => s.Grade)
      .SelectMany(max => max)
      .SubscribeConsole("Maximal object by grade");

    grades.OnNext(new StudentGrade(id: "1", name: "A", grade: 85.0f));
    grades.OnNext(new StudentGrade(id: "2", name: "B", grade: 95.0f));
    grades.OnNext(new StudentGrade(id: "3", name: "C", grade: 91.0f));
    grades.OnCompleted();
  }

  static void AggregateCustomized()
  {
    Observable.Range(1, 5)
      .Aggregate(1, (x, y) => x * y)
      .SubscribeConsole("Aggregated -");
  }

  static void ScanCustomized()
  {
    Observable.Range(1, 5)
      .Scan(1, (x, y) => x * y)
      .SubscribeConsole("Scanned =");
  }
}