let getEvenNumbers numbers = 
  Seq.filter(fun x -> x % 2 = 0) numbers

printfn "Even numbers: %A" (getEvenNumbers [1; 2; 3; 4; 5; 6])

let squareNumbers numbers = 
  Seq.map(fun x -> x * x) numbers

let getEvenNumbersAndSquare numbers = 
  numbers |> getEvenNumbers |> squareNumbers

printfn "Squared even numbers: %A" (getEvenNumbersAndSquare [1; 2; 3; 4; 5; 6])