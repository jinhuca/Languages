let getEvenNumbers: int list -> int seq = Seq.filter(fun (number: int) -> number % 2 =0)
let squareNumbers: int seq -> int seq = Seq.map (fun x -> x * x)
let getEvenNumbersThenSquare = getEvenNumbers >> squareNumbers

let evenNumbers = [1..10] |> getEvenNumbers
printfn $"{evenNumbers}"

let evenNumbersSquared = [1..10] |> getEvenNumbersThenSquare
printfn $"{evenNumbersSquared}" 