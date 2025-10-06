using System;

namespace D22_TemplateMethod
{
  public class SaloonBooklet : AbstractBookletPrinter
  {
    protected internal override int PageCount
    {
      get
      {
        return 100;
      }
    }

    protected internal override void PrintFrontCover()
    {
      Console.WriteLine("Printing front cover for Saloon car booklet");
    }

    protected internal override void PrintTableOfContents()
    {
      Console.WriteLine("Printing table of contents for Saloon car booklet");
    }

    protected internal override void PrintPage(int pageNumber)
    {
      Console.WriteLine("Printing page " + pageNumber + " for Saloon car booklet");
    }

    protected internal override void PrintIndex()
    {
      Console.WriteLine("Printing index for Saloon car booklet");
    }

    protected internal override void PrintBackCover()
    {
      Console.WriteLine("Printing back cover for Saloon car booklet");
    }
  }
}
