using static System.Console;

var httpClient1_ = new HttpClient();
Task<HttpResponseMessage> requestTask = httpClient1_.GetAsync("http://ReactiveX.io");
WriteLine($"The request was sent, status: {requestTask.Status}");
WriteLine(requestTask.Result.Headers);
WriteLine($"The request was sent, status: {requestTask.Status}");
ReadLine();

var httpClient2_ = new HttpClient();
httpClient2_
  .GetAsync("http://ReactiveX.io")
  .ContinueWith(requestTask =>
  {
    WriteLine($"The request was sent, status: {requestTask.Status}");
    WriteLine(requestTask.Result.Headers);
  });
ReadLine();