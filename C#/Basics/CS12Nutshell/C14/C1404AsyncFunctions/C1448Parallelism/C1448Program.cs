await Go();

async Task Go()
{
  var task1 = PrintAnswerToLife();
  var task2 = PrintAnswerToLife();
  await task1;
  await task2;
  Console.WriteLine("Done.");
}

async Task PrintAnswerToLife()
{
  int answer = await GetAnswerToLife();
  Console.WriteLine(answer);
}

async Task<int> GetAnswerToLife()
{
  await Task.Delay(1000);
  int answer = 21 * 2;
  return answer;
}