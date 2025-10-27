using static System.Console;

var httpClient1_ = new HttpClient();
Task<HttpResponseMessage> requestTask = httpClient1_.GetAsync("http://ReactiveX.io");
WriteLine($"The request was sent, status: {requestTask.Status}");
WriteLine(requestTask.Result.Headers);
WriteLine($"The request was sent, status: {requestTask.Status}");
ReadLine();

var httpClient2_ = new HttpClient();

Action<Task<HttpResponseMessage>> continuationAction = static requestTask => {
    WriteLine($"The request was sent, status: {requestTask.Status}");
    WriteLine(requestTask.Result.Headers);
};

Task continuationTask = httpClient2_
  .GetAsync("http://ReactiveX.io")
  .ContinueWith(continuationAction);
ReadLine();