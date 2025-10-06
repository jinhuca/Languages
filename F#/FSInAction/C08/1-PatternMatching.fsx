module PatternMatching

// Listing 8.1 Single value pattern matching
let value = System.ConsoleModifiers.Alt

let description =
  match value with
  | System.ConsoleModifiers.Alt -> "Alt was pressed."
  | System.ConsoleModifiers.Control -> "You hit control!"
  | System.ConsoleModifiers.Shift -> "Shift held down..."
  | _ -> "Some modifier was pressed."

// Listing 8.2 Tuple pattern matching
let customerDetails = 2, true

let canTakeOutALoan = 
  match customerDetails with 
  | 0, true -> false
  | 0, false -> false
  | 1, true -> false
  | 1, false -> true
  | 2, false -> true
  | 2, true -> true
  | _, true -> true
  | _, false -> true

// Simplifying pattern matches
let canTakeOutALoanV2 =
  match customerDetails with
  | 0, _ -> false
  | 1, true -> false
  | 1, false -> true
  | _ -> true

let canTakeOutALoanV3 =
  match customerDetails with
  | 0, _
  | 1, true -> false
  | 1, false
  | _ -> true

let canTakeOutALoanV4 =
  match customerDetails with
  | 0, _
  | 1, true -> false
  | _ -> true

// Listing 8.3 Record pattern matching
type CustomerDetails = {
  YearsOfHistory: int
  HasOverdraft: bool
}

let customerDetailsRecord = {
  YearsOfHistory = 2
  HasOverdraft = true
}

let canTakeOutALoanRecord =
  match customerDetailsRecord with
  | { YearsOfHistory = 0 } -> false
  | {
      YearsOfHistory = 1
      HasOverdraft = true
    } -> false
  | {
      YearsOfHistory = 1
      HasOverdraft = false
    } -> true
  | _ -> true

// Listing 8.4 Pattern matching type inference
let canTakeOutALoanRecordFn customer = 
  match customer with 
  | { YearsOfHistory = 0 } -> false 
  | { YearsOfHistory = 1; HasOverdraft = true } -> false 
  | { YearsOfHistory = 1; HasOverdraft = false } -> true
  | _ -> true

// Listing 8.5 Using When within Pattern Matches
type CustomerDetailsOverdraft = { 
  YearsOfHistory: int
  HasOverdraft: bool
  Overdraft: int
}

let customerDetailsWithOverdraftRecord = {
  YearsOfHistory = 2
  HasOverdraft = true
  Overdraft = 500
}

let canTakeOutALoanWithGuard = 
  match customerDetailsWithOverdraftRecord with 
  | { YearsOfHistory = 0 } -> false
  | { 
      YearsOfHistory = 1 
      HasOverdraft = true
    } when customerDetailsWithOverdraftRecord.Overdraft > 500 -> false 
  | { YearsOfHistory = 1 } -> true
  | _ -> true
