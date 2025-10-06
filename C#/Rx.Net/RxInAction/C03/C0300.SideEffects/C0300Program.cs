namespace C0300.SideEffects;

internal class C0300Program
{
	static void Main(string[] args)
	{
		WriteRedMessage("Hello, World!");
	}

	private static void WriteRedMessage(string message)
	{
		Console.ForegroundColor = ConsoleColor.Red;
		Console.WriteLine(message);
	}
}