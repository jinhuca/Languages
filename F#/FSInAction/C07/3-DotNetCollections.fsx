// Listing 7.5 Creating and consuming an Array
let numbersArray = [| 1..10 |]
let secondElementArray = numbersArray[1]
let squaresArray = numbersArray |> Array.map (fun x -> x * x)

// Listing 7.6 Creating and consuming a Sequence
let numbers = seq [ 1..10 ]
let secondElement = numbers |> Seq.item 1
let squares = numbers |> Seq.map (fun x -> x * x)

// Listing 7.7 Creating and consuming a read-only dictionary
let data = [ "Isaac", "F#"; "Fred", "C#"; "Sam", "F#"; "Jo", "PHP" ]
let lookup = readOnlyDict data
let isaacsLang = lookup["Isaac"]
// lookup["Isaac"] <- "Python"

// Listing 7.8 Creating and consuming an F# map
let lookupMap = Map data
let newLookupMap = lookupMap.Add("Isaac", "Python")
//let newLookupMap = lookupMap |> Map.add "Isaac" "Python"

// Listing 7.9 Working with F# sets
type Employee = { Name: string }
let salesEmployees = Set [ { Name = "Isaac" }; { Name = "Brian" }]
let bonusEmployees = Set [ { Name = "Isaac" }; { Name = "Tanya" }]

let allBonusesForSalesStaff =
  salesEmployees |> Set.isSubset bonusEmployees

let salesWithoutBonuses =
  salesEmployees - bonusEmployees

// Listing 7.10
#time
let largeComputation =
  seq { 1..100000000 }
  |> Seq.map (fun x -> x * x)
  |> Seq.rev
  |> Seq.filter (fun x -> x % 2 = 0)
  |> Seq.toArray

// Listing 7.11
open System
let comp = seq {
  1
  2
  if DateTime.Today.DayOfWeek = DayOfWeek.Tuesday then 99
  4
}