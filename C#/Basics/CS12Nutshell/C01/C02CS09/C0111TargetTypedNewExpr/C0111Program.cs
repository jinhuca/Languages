System.Text.StringBuilder sb1 = new();
System.Text.StringBuilder sb2 = new("Test");

class Foo
{
  private System.Text.StringBuilder sb;
  public Foo(string initialValue) => sb = new(initialValue);
  void MyMethod(System.Text.StringBuilder sb){}
}
