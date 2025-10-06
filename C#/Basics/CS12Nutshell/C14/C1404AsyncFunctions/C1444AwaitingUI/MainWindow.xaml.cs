using System;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;

namespace C1444AwaitingUI
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
      _button.Click += (sender, args) =>
      {
        _button.IsEnabled = false;
        Task.Run(() => Go());
      };
    }

    void Go()
    {
      // Notice the race condition (run it and look at what's wrong with the results):
      for (int i = 1; i < 5; i++)
      {
        int result = GetPrimesCount(i * 1000000, 1000000);
        Dispatcher.BeginInvoke(new Action(() =>
        _results.Text += result + " primes between " + (i * 1000000) + " and " + ((i + 1) * 1000000 - 1) + Environment.NewLine));
      }
      Dispatcher.BeginInvoke(new Action(() => _button.IsEnabled = true));
    }

    int GetPrimesCount(int start, int count)
    {
      return
        ParallelEnumerable.Range(start, count).Count(n =>
          Enumerable.Range(2, (int)Math.Sqrt(n) - 1).All(i => n % i > 0));
    }
  }
}
