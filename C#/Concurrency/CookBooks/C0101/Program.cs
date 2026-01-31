using System.Diagnostics;

namespace C0101;

internal class Program {
  static async Task Main(string[] args) {
    Console.WriteLine("Hello, World!");
    await DoSomethingAsync();
    
    Console.ReadLine();
  }

  static async Task DoSomethingAsync() {
    int value = 13;
    await Task.Delay(1000);
    Console.WriteLine(value);
    value *= 2;
    await Task.Delay(1000);
    Console.WriteLine(value);
  }
}
