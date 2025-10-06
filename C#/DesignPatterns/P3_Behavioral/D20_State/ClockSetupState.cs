namespace D20_State
{
  public interface ClockSetupState
  {
    void PreviousValue();
    void NextValue();
    void SelectValue();

    string Instructions { get; }
    int SelectedValue { get; }
  }
}
