let name = "isaac"
let time = System.DateTime.UtcNow
printfn $"Hello from F#! My name is {name}, the time is {time}"

let version = 8
printfn $"F# {version} is cool"

let greetPerson name age =
  $"Hello, {name}. You are {age} years old."

let result = greetPerson "Fred" 21
printfn "%s" result
