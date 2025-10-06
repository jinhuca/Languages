namespace C0310.AnonymousTypes;

internal class C0310Program
{
  static void Main()
  {
    AnonymousTypeDemo();
  }

  private static void AnonymousTypeDemo()
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

    var authorBooks =
      from author in authors
      from book in books
      where author.Id == book.Id
      select new { author, book };

    foreach (var authorbook in authorBooks)
    {
      Console.WriteLine($"{authorbook} wrote the book: {authorbook.book}");
    }
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

  public override string ToString()
  {
    return Name;
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

  public override string ToString()
  {
    return Title;
  }
}