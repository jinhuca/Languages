using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace D18_Memento
{
  public class SpeedometerMemento2
  {
    public SpeedometerMemento2(Speedometer2 speedometer)
    {
      // Serialize...
      Stream stream = File.Open("speedometer.ser", FileMode.Create);
      BinaryFormatter formatter = new BinaryFormatter();
      formatter.Serialize(stream, speedometer);
      stream.Close();
    }

    public virtual Speedometer2 RestoreState()
    {
      // Deserialize...
      Speedometer2 speedo;
      Stream stream = File.Open("speedometer.ser", FileMode.Open);
      BinaryFormatter formatter = new BinaryFormatter();
      speedo = (Speedometer2)formatter.Deserialize(stream);
      stream.Close();
      return speedo;
    }

  }
}
