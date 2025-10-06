namespace P094;

using System.Reactive;
using System.Reactive.Disposables;

public class ChatConnectionObservable : ObservableBase<string>
{
  private readonly IChatConnectionEventAggregator _chatConnectionEventAggregator;

  public ChatConnectionObservable(IChatConnectionEventAggregator chatConnectionEventAggregator)
  {
    _chatConnectionEventAggregator = chatConnectionEventAggregator;
  }

  protected override IDisposable SubscribeCore(IObserver<string> observer)
  {
    Action<string> received = observer.OnNext;
    Action closed = observer.OnCompleted;
    Action<Exception> error = observer.OnError;

    _chatConnectionEventAggregator.Received += received;
    _chatConnectionEventAggregator.Closed += closed;
    _chatConnectionEventAggregator.Error += error;

    _chatConnectionEventAggregator.NotifyReceived("Hello");
    _chatConnectionEventAggregator.NotifyReceived("Kitty");
    _chatConnectionEventAggregator.NotifyReceived("bye!");

    return Disposable.Create(() =>
    {
      _chatConnectionEventAggregator.Received -= received;
      _chatConnectionEventAggregator.Closed -= closed;
      _chatConnectionEventAggregator.Error -= error;
      _chatConnectionEventAggregator.Disconnect();
    });
  }
}