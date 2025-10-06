await Go();

async Task Go()
{
  await PrintAnswerToLife();
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