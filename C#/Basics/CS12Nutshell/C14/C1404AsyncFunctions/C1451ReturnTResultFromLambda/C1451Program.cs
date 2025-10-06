Func<Task<int>> unnamed = async () =>
{
  await Task.Delay(1000);
  return 123;
};

int answer = await unnamed();
Console.WriteLine(answer);