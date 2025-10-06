using System.Reactive.Linq;
using System.Windows;
using System.Windows.Input;

namespace C0204;

public partial class MainWindow : Window
{
  public MainWindow()
  {
    InitializeComponent();
    var mouseMove_ = Observable
      .FromEventPattern<MouseEventArgs>(this, "MouseMove")
      .Sample(TimeSpan.FromSeconds(0.5));

    var disp = mouseMove_.Subscribe(args => _ = Dispatcher.BeginInvoke(() =>
    {
      txtBox.Text = args.EventArgs.GetPosition(this).ToString();
    }));
    Closed += (o, e) => disp.Dispose();
  }

  private new void MouseMove(object sender, MouseEventArgs args)
  {
    _ = Dispatcher.BeginInvoke(() =>
    {
      txtBox.Text = args.GetPosition(this).ToString();
    });
  }
}