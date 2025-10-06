Thread t = new Thread(() => Print("Hello from t!"));
t.Start();

void Print(string message)=> Console.WriteLine(message);