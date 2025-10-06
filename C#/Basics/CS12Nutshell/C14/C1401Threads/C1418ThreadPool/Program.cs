// Task is in System.Threading.Tasks
Task.Run(() => Console.WriteLine("Hello from the thread pool."));

// The old-school way:
ThreadPool.QueueUserWorkItem(notUsed => Console.WriteLine("Hello, old-school."));

Console.ReadLine();