type OverdraftDetails =
  {
    Approved : bool
    MaxAmount : decimal
    CurrentAmount : decimal
  }

type CustomerWithOverdraft =
  {
    YearsOfHistory : int
    Overdraft : OverdraftDetails
  }

let canTakeOutALoanRecursive customer =
  match customer with
  | { YearsOfHistory = 0; Overdraft = { Approved = true } } -> true
  | { YearsOfHistory = 0 } -> false
  | { YearsOfHistory = 1; Overdraft = { Approved = true } } -> true
  | { YearsOfHistory = 1 } -> false
  | _ -> true
