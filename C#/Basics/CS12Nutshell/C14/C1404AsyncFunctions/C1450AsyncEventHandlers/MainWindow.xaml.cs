using System.Threading.Tasks;
using System.Windows;

namespace C1450AsyncEventHandlers
{
  public partial class MainWindow : Window
  {
    public MainWindow()
    {
      InitializeComponent();
      btn.Click += async (s, e) =>
        {
          await Task.Delay(1000);
          btn.Content = "Done";
        };
    }
  }
}
