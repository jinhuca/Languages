using System;

namespace D22_TemplateMethod
{
  public class Program
  {
    public static void Main(string[] args)
    {
      Console.WriteLine("About to print a booklet for saloon cars");
      AbstractBookletPrinter saloonBooklet = new SaloonBooklet();
      saloonBooklet.Print();

      Console.WriteLine("About to print a service history booklet");
      AbstractBookletPrinter serviceBooklet = new ServiceHistoryBooklet();
      serviceBooklet.Print();
    }
  }
}
