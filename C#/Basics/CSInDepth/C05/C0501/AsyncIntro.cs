namespace C0501;

public partial class AsyncIntro : Form
{
  private static readonly HttpClient Client = new();
  private readonly Label _label;
  private readonly Button _button;

  public AsyncIntro()
  {
    _label = new Label
    {
      Location = new Point(10, 20),
      Text = "Length"
    };
    _button = new Button
    {
      Location = new Point(10, 50),
      Text = "Click"
    };
    _button.Click += DisplayWebSiteLength;
    AutoSize = true;
    Controls.Add(_label);
    Controls.Add(_button);
    InitializeComponent();
  }

  private async void DisplayWebSiteLength(object? sender, EventArgs e)
  {
    _label.Text = "Fetching...";
    string text_ = await Client.GetStringAsync("http://csharpindepth.com");
    _label.Text = text_.Length.ToString();
  }

  static void Main()
  {
    Application.Run(new AsyncIntro());
  }
}