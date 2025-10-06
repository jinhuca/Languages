using System.Reactive.Linq;
using System.Windows;

namespace P251ObserveOnDispatcher;

public partial class MainWindow : Window
{
  public MainWindow()
  {
    InitializeComponent();
    Observable.FromEventPattern(TextBox, nameof(TextBox.TextChanged))
      .Select(_ => TextBox.Text)
      .Throttle(TimeSpan.FromMilliseconds(400))
      .ObserveOn(SynchronizationContext.Current!)
      .Subscribe(s => ThrottledResults.Items.Add(s));
  }
}