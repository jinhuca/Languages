using System.Reactive.Linq;
using System.Windows;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Shapes;

namespace P154;

public partial class MainWindow : Window
{
  public MainWindow()
  {
    InitializeComponent();
    SubscribeEvents();
  }

  public void SubscribeEvents()
  {
    var mouseDowns = Observable.FromEventPattern<MouseButtonEventArgs>(this, "MouseDown");
    var mouseUp = Observable.FromEventPattern<MouseButtonEventArgs>(this, "MouseUp");
    var movements = Observable.FromEventPattern<MouseEventArgs>(this, "MouseMove");

    var subscription = movements
      .SkipUntil(mouseDowns.Do(_ =>
      {
        var line_ = new Polyline() { Stroke = Brushes.Black, StrokeThickness = 3 };
        canvas.Children.Add(line_);
      }))
      .TakeUntil(mouseUp)
      .Select(m => m.EventArgs.GetPosition(this))
      .Repeat()
      .Subscribe(pos => line.Points.Add(pos));
  }
}