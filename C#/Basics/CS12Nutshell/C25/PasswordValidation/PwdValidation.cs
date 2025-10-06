using System.Text.RegularExpressions;

namespace PasswordValidation
{
  public class PwdValidation
  {
    public bool Validate(string password)
    {
      if(password == null)
        return false;

      const string pwPattern = @"^(?=.*\d)(?=.*).{8,16}$";
      var pattern_ = new Regex(pwPattern, RegexOptions.Compiled);
      return pattern_.IsMatch(password);
    }
  }
}