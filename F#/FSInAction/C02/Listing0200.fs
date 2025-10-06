module Listing0200

// Define a function
let getEvenNumbers : (int seq -> int seq) = Seq.filter(fun number -> number % 2 = 0)

// Apply the function with input data
let evenNumbers = [1..10] |> getEvenNumbers

// Evaluate the result of the function invocation
let result1 = Seq.toList evenNumbers

// Define another function
let squareNumbers : (int seq -> int seq) = Seq.map(fun x -> x * x)

// Compose the functions into new function:
let getEvenNumbersThenSquare = getEvenNumbers >> squareNumbers

let evenNumbersSquared = getEvenNumbersThenSquare [1..10]
let result2 = Seq.toArray evenNumbersSquared
