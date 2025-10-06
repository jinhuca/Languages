using System.Threading;
using System.Windows;
using System.Windows.Controls;

namespace C1417SynchronizationContext
{
  public partial class MainWindow : Window
  {
    TextBox txtMessage;
    SynchronizationContext _uiSyncContext;

    public MainWindow()
    {
      InitializeComponent();
      WindowStartupLocation = WindowStartupLocation.CenterScreen;
      Content = txtMessage = new TextBox { Width = 250, Margin = new Thickness(10), Text = "Ready" };

      _uiSyncContext = SynchronizationContext.Current;
      new Thread(Work).Start();
    }

    void Work()
    {
      Thread.Sleep(5000);           // Simulate time-consuming task
      UpdateMessage("The answer");
    }

    void UpdateMessage(string message)
    {
      // Marshal the delegate to the UI thread:
      _uiSyncContext.Post(_ => txtMessage.Text = message, null);
    }
  }
}
