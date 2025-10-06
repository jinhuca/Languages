await Go();

async Task Go()
{
  await PrintAnswerToLife();
  Console.WriteLine("Done");
}

async Task PrintAnswerToLife()
{
  await Task.Delay(5000);
  int answer = 21 * 2;
  Console.WriteLine(answer);
}