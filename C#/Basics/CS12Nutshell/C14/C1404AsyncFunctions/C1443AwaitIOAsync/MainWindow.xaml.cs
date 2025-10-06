using System;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;

namespace C1443AwaitIOAsync
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
      string[] urls = "www.albahari.com www.oreilly.com www.linqpad.net".Split();
      int totalLength = 0;
      try
      {
        foreach (string url in urls)
        {
          var uri = new Uri("http://" + url);
          byte[] data = await new HttpClient().GetByteArrayAsync(uri);
          _results.Text += "Length of " + url + " is " + data.Length + Environment.NewLine;
          totalLength += data.Length;
        }
        _results.Text += "Total length: " + totalLength;
      }
      catch (WebException ex)
      {
        _results.Text += "Error: " + ex.Message;
      }
      finally { _button.IsEnabled = true; }
    }

    Task<int> GetPrimesCountAsync(int start, int count)
    {
      return Task.Run(() =>
       ParallelEnumerable.Range(start, count).Count(n =>
       Enumerable.Range(2, (int)Math.Sqrt(n) - 1).All(i => n % i > 0)));
    }
  }
}
