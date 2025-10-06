using System;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;

namespace C1442AwaitAsync
{
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

    async void Go()
    {
      _button.IsEnabled = false;

      for (int i = 1; i < 5; i++)
        _results.Text += await GetPrimesCountAsync(i * 2000000, 2000000) +
          " primes between " + (i * 2000000) + " and " + ((i + 1) * 2000000 - 1) + Environment.NewLine;

      _button.IsEnabled = true;
    }

    Task<int> GetPrimesCountAsync(int start, int count)
    {
      return Task.Run(() =>
       ParallelEnumerable.Range(start, count).Count(n =>
       Enumerable.Range(2, (int)Math.Sqrt(n) - 1).All(i => n % i > 0)));
    }
  }
}
