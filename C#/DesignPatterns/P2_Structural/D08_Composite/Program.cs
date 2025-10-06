using static System.Console;

namespace D08Composite
{
  public class Program
  {
    public static void Main(string[] args)
    {
      Item nut = new Part("Nut", 5);
      Item bolt = new Part("Bolt", 9);
      Item panel = new Part("Panel", 35);

      Item gizmo = new Assembly("Gizmo");
      gizmo.AddItem(panel);
      gizmo.AddItem(nut);
      gizmo.AddItem(bolt);

      Item widget = new Assembly("Widget");
      widget.AddItem(gizmo);
      widget.AddItem(nut);

      // Display the items
      WriteLine(nut);
      WriteLine(bolt);
      WriteLine(panel);
      WriteLine(gizmo);
      WriteLine(widget);
    }
  }
}
