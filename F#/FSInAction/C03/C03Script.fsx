let myFunction arg1 arg2 = arg1 + arg2
let myValue = 99

// Listing 3.1
let addTenThenDouble theNumber = 
  let addedTen = theNumber + 10
  let answer = addedTen * 2
  printfn $"({theNumber} + 10) * 2 is {answer}"
  let website = System.Uri "https://fsharp.org"
  answer

let result1 = addTenThenDouble 10

// Listing 3.2
let addTenThenDoubleVerbose (theNumber: int) : int =
  let addedTen: int = theNumber + 10
  let answer: int = addedTen * 2
  answer

let result2 = addTenThenDoubleVerbose 10

// The let keyword
let doACalculation theNumber =
  let twenty = 20
  let answer = twenty + theNumber
  let foo = System.Uri "https://fsharp.org"
  answer

let result3 = doACalculation 10

// Exercise 3.1
let exercise31 (arg1 : float) (arg2 : float) (arg3 : float) =
  let inProgress = arg1 + arg2
  let answer = inProgress * arg3
  $"The answer is {answer}"

let result4 = exercise31 10.2 12.3 3.

// Non-nested function
let fname = "Frank"
let sname = "Schmidt"
let fullName = $"{fname} {sname}"
let greetingText = $"Greetings, {fullName}"

// Nested functions
let greetingTextWithFunction person =
  let makeFullName fname sname = $"{fname} {sname}"
  let fullName = makeFullName "Frank" "Schmidt"
  $"Greetings {fullName} from {person}"

let result5 = greetingTextWithFunction "Jon"

// Listing 3.3
let greetingTextWithFunction2 =
  let city = "London"
  let makeFullName fname sname = 
    $"{fname} {sname}"
  let fullName = makeFullName "Frank" "Schmidt"
  // let surnameCity = $"{sname} from {city}"
  $"Greeting, {fullName}"

let r3 = greetingTextWithFunction2

// Listing 3.4 Working with type annotations
let add a b =
  let answer = a + b
  answer

let result7 = add 5 6

let explicit = ResizeArray<int>()
let typeHole: ResizeArray<_> = ResizeArray<_>()
typeHole.Add "99"

let omitted = ResizeArray()
omitted.Add "10"

let name = "John", "Doe"
let firstName, lastName = name

let combineElements<'T> (a: 'T) (b: 'T) (c: 'T) =
  let output = ResizeArray<'T>()
  output.Add a
  output.Add b
  output.Add c
  output

let c1 = combineElements<int> 1 2 3
let c2 = combineElements<string> "Hello" "F#"

let combineElements' a b c =
  let output = ResizeArray()
  output.Add a
  output.Add b
  output.Add c
  output

let result = (combineElements' 1 2 3).ToArray
