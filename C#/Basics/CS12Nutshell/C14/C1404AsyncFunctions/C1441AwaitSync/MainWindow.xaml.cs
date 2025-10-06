using System;
using System.Linq;
using System.Windows;
using System.Windows.Controls;

namespace C1441AwaitSync
{
  // Notice how the window becomes unresponsive while working
  public partial class MainWindow : Window
  {
    Button _button = new Button { Content = "Go" };
    TextBlock _results = new TextBlock();

    public MainWindow()
    {
      InitializeComponent();
      var panel = new StackPanel();
      panel.Children.Add(_button);
      panel.Children.Add(_results);
      Content = panel;
      _button.Click += (sender, args) => Go();
    }

    void Go()
    {
      for (int i = 1; i < 5; i++)
        _results.Text += GetPrimesCount(i * 2000000, 2000000) +
          " primes between " + (i * 2000000) + " and " + ((i + 1) * 2000000 - 1) + Environment.NewLine;
    }

    int GetPrimesCount(int start, int count)
    {
      return ParallelEnumerable.Range(start, count).Count(n =>
    Enumerable.Range(2, (int)Math.Sqrt(n) - 1).All(i => n % i > 0));
    }
  }
}
