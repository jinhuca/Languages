namespace Module.Infrastructure.Units;

[TestClass]
public class ConsoleStateIdTests
{
  [TestMethod]
  public void StateEqualityTest()
  {
    ConsoleStateId state1_ = ConsoleStateId.Idle;
    ConsoleStateId state2_ = ConsoleStateId.Idle;
    Assert.IsTrue(state1_ == state2_);
    Assert.IsTrue(state1_.Name == state2_.Name);
    Assert.IsTrue(state1_.Value == state2_.Value);
  }

  [TestMethod]
  public void StateInequalityTest()
  {
    ConsoleStateId state1_ = ConsoleStateId.Idle;
    ConsoleStateId state2_ = ConsoleStateId.Ready;
    Assert.IsFalse(state1_ == state2_);
    Assert.IsFalse(state1_.Equals(state2_));
    Assert.IsFalse(state1_.Name == state2_.Name);
    Assert.IsFalse(state1_.Value == state2_.Value);
  }

  [TestMethod]
  public void StateNamesTest()
  {
    Assert.IsTrue(ConsoleStateId.Unknown.Name == "Unknown");
    Assert.IsTrue(ConsoleStateId.Idle.Name == "Idle");
    Assert.IsTrue(ConsoleStateId.Ready.Name == "Ready");
    Assert.IsTrue(ConsoleStateId.Inflation.Name == "Inflation");
    Assert.IsTrue(ConsoleStateId.Transition.Name == "Transition");
    Assert.IsTrue(ConsoleStateId.Ablation.Name == "Ablation");
    Assert.IsTrue(ConsoleStateId.Thawing.Name == "Thawing");
    Assert.IsTrue(ConsoleStateId.Exception.Name == "Exception");
  }

  [TestMethod]
  public void StateValuesTest()
  {
    Assert.IsTrue(ConsoleStateId.Unknown.Value == 0);
    Assert.IsTrue(ConsoleStateId.Idle.Value == 256);
    Assert.IsTrue(ConsoleStateId.Ready.Value == 512);
    Assert.IsTrue(ConsoleStateId.Inflation.Value == 768);
    Assert.IsTrue(ConsoleStateId.Transition.Value == 1024);
    Assert.IsTrue(ConsoleStateId.Ablation.Value == 1280);
    Assert.IsTrue(ConsoleStateId.Thawing.Value == 1536);
    Assert.IsTrue(ConsoleStateId.Exception.Value == 1792);
  }
}