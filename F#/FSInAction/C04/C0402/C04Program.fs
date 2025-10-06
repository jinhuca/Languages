// Page 53: Unit
let printAddition a b =
  let answer = a + b
  printfn $"{a} plus {b} equals {answer}"

printAddition 1 3

let getTheCurrentTime = System.DateTime.Now
let x = getTheCurrentTime
printfn $"{x}"

let y = getTheCurrentTime
printfn $"{y}"

let getTheCurrentTimeFunction () = System.DateTime.Now
let x1 = getTheCurrentTimeFunction ()
printfn $"{x1}"

let y1 = getTheCurrentTimeFunction ()
printfn $"{y1}"

let addDays days =
  let newDays = System.DateTime.Today.AddDays days
  printfn $"You gave me {days} days and I gave you {newDays}"
  newDays
let result3 = addDays 3

let addSeveralDays () =
  ignore (addDays 2)
  ignore (addDays 5)
  addDays 7

let result4 = addSeveralDays ()

