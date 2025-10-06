using System.Xml.Linq;

Book[] books_ =
[
  new Book("Ajax in Action", "Manning", 2005),
  new Book("Windows Forms in Action", "Manning", 2006),
  new Book("RSS and Atom in Action", "Manning", 2006)
];

XElement xml_ = new XElement("books",
  from book_ in books_
  where book_.Year == 2006
  select new XElement("book",
    new XAttribute("title", book_.Title),
    new XElement("publisher", book_.Publisher))
);

Console.WriteLine(xml_);

class Book
{
  public string Publisher;
  public string Title;
  public int Year;

  public Book(string title, string publisher, int year)
  {
    Title = title;
    Publisher = publisher;
    Year = year;
  }
}