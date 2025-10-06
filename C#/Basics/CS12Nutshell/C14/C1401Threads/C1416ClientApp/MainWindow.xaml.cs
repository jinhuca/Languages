using System;
using System.Threading;
using System.Windows;
using System.Windows.Controls;

namespace C1416ClientApp
{
  public partial class MainWindow : Window
  {
    TextBox txtMessage;
    public MainWindow()
    {
      InitializeComponent();
      WindowStartupLocation = WindowStartupLocation.CenterScreen;
      Content = txtMessage = new TextBox { Width = 250, Margin = new Thickness(10), Text = "Ready" };
      new Thread(Work).Start();
    }

    void Work()
    {
      Thread.Sleep(3000);           // Simulate time-consuming task
      UpdateMessage("The answer");
    }

    void UpdateMessage(string message)
    {
      Action action = () => txtMessage.Text = message;
      Dispatcher.BeginInvoke(action);
    }
  }
}
