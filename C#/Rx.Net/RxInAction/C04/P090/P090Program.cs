using Helpers;
using P090;

var numbers_ = new NumbersObservable(5);
var subscription1_ = numbers_.Subscribe(new MyAnotherObserver<int>("another"));
subscription1_.Dispose();

Console.WriteLine();

var sub2 = numbers_.SubscribeConsole("ConsoleObserver: ");
sub2.Dispose();


//var subscription_ = numbers_.Subscribe(new MyObserver("My Observer"));
//subscription_.Dispose();
