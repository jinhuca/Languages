using Ardalis.SmartEnum;

namespace Module.Infrastructure;

public sealed class ConsoleStateId : SmartEnum<ConsoleStateId>
{
  private static readonly Dictionary<string, int> StateNameValueDictionary = new()
  {
    { StateNames.Unknown, StateValues.Unknown },
    { StateNames.Idle, StateValues.Idle },
    { StateNames.Ready, StateValues.Ready },
    { StateNames.Inflation, StateValues.Inflation },
    { StateNames.Transition, StateValues.Transition },
    { StateNames.Ablation, StateValues.Ablation },
    { StateNames.Thawing, StateValues.Thawing },
    { StateNames.Exception, StateValues.Exception }
  };

  public static readonly ConsoleStateId Idle = new(StateNames.Idle, StateNameValueDictionary[StateNames.Idle]);
  public static readonly ConsoleStateId Ready = new(StateNames.Ready, StateNameValueDictionary[StateNames.Ready]);
  public static readonly ConsoleStateId Inflation = new(StateNames.Inflation, StateNameValueDictionary[StateNames.Inflation]);
  public static readonly ConsoleStateId Transition = new(StateNames.Transition, StateNameValueDictionary[StateNames.Transition]);
  public static readonly ConsoleStateId Ablation = new(StateNames.Ablation, StateNameValueDictionary[StateNames.Ablation]);
  public static readonly ConsoleStateId Thawing = new(StateNames.Thawing, StateNameValueDictionary[StateNames.Thawing]);
  public static readonly ConsoleStateId Exception = new(StateNames.Exception, StateNameValueDictionary[StateNames.Exception]);
  public static readonly ConsoleStateId Unknown = new(StateNames.Unknown, StateNameValueDictionary[StateNames.Unknown]);

  private ConsoleStateId(string name, int value) : base(name, value)
  {
  }
}

public static class StateNames
{
  public const string Unknown = "Unknown";
  public const string Idle = "Idle";
  public const string Ready = "Ready";
  public const string Inflation = "Inflation";
  public const string Transition = "Transition";
  public const string Ablation = "Ablation";
  public const string Thawing = "Thawing";
  public const string Exception = "Exception";
}

public static class StateValues
{
  public const int Unknown = 0;
  public const int Idle = 256;
  public const int Ready = 512;
  public const int Inflation = 768;
  public const int Transition = 1024;
  public const int Ablation = 1280;
  public const int Thawing = 1536;
  public const int Exception = 1792;
}