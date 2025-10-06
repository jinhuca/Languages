using System.Reactive.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace P195DistinctUntilChanged;

public partial class MainWindow : Window
{
  public MainWindow()
  {
    InitializeComponent();
    Observable
      .FromEventPattern(SearchTerm, "TextChanged")
      .Select(_=>SearchTerm.Text)
      .Throttle(TimeSpan.FromMicroseconds(1500))
      .DistinctUntilChanged()
      .ObserveOn(SynchronizationContext.Current)
      .Subscribe(s => Terms.Items.Add(s));

  }


}