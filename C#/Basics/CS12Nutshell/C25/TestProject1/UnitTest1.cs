using PasswordValidation;

namespace TestProject1
{
  [TestClass]
  public class UnitTest1
  {
    private readonly PwdValidation _pwdValidation;

    public UnitTest1()
    {
      _pwdValidation = new PwdValidation();
    }

    [TestMethod]
    [DataRow("fds1%^&j", "8 long with 1 digit")]
    [DataRow("Qp#C2003","")]
    [DataRow("1234567890", "10 digits")]
    [DataRow("a@bcdefg2w1@09k", "15 characters")]
    [DataRow("a_op0b%$fg2", "")]
    public void IsValid(string input, string msg)
    {
      Assert.IsTrue(_pwdValidation.Validate(input), msg);
    }

    [TestMethod]
    [DataRow(null, "null")]
    [DataRow("", "empty")]
    [DataRow("a", "a character")]
    [DataRow("&", "a character")]
    [DataRow("1", "a digit")]
    [DataRow("d%$^abcdefgh", "no digit")]
    [DataRow("aes3d_9", "seven characters")]
    [DataRow("asdfej&8(9_qw345y", "17 characters")]
    [DataRow("aklfke.kwedsffkjlk212dfkj", "too long")]
    public void IsInvalid(string input, string msg)
    {
      Assert.IsFalse(_pwdValidation.Validate(input), msg);
    }
  }
}