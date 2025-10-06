using static System.Console;

namespace C0309.LINQs;

internal class C0309Program
{
  static void Main()
  {
    ChainQueryDemo();
    //NestedQueriesDemo();
  }

  private static void ChainQueryDemo()
  {
    var numbers = new List<int> { 1, 35, 22, 6, 10, 11 };
    var result = numbers
      .Where(x => x % 2 == 1)
      .Where(x => x > 10)
      .Select(x => x + 2)
      .Distinct()
      .OrderBy(x => x);
    foreach (var number in result)
    {
      WriteLine(number);
    }
  }

  private static void NestedQueriesDemo()
  {
    var authors = new[]
    {
      new Author(1, "Tamir Dresher"),
      new Author(2, "John Skeet")
    };
    var books = new[]
    {
      new Book("Rx.NET in Action", 1),
      new Book("C# in Depth", 2),
      new Book("Real-World Functional Programming", 2)
    };
    var authorsBooks = authors
      .SelectMany(author => books, (author, book) => new { author, book })
      .Where(t => t.book.Id == t.author.Id)
      .Select(t => t.author.Name + " wrote the book: " + t.book.Title);
    
    foreach (var authorbook in authorsBooks)
    {
      WriteLine(authorbook);
    }
  }
}

internal class Book
{
  public string Title { get; set; }
  public int Id { get; set; }
  public Book(string title, int id)
  {
    Title = title;
    Id = id;
  }
}

internal class Author
{
  public int Id { get; set; }
  public string Name { get; set; }

  public Author(int id, string name)
  {
    Id = id;
    Name = name;
  }
}