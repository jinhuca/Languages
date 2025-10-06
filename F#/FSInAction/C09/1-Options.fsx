// Options for null - T option or option<T>

// (1) define option symbols with some content and without anything:
let optionalNumber1 : int option = Some 10
let optionalNumber2 : int option = None

// (2) get value via pattern matching
let deciper (number : int option) =
  match number with
  | Some num -> $"The number is {num}"
  | None -> "There is no number"

printfn $"{deciper optionalNumber1}"
printfn $"{deciper optionalNumber2}"
