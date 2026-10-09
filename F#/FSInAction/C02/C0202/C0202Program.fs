let name = "Issac"
let time = System.DateTime.UtcNow
printfn $"Hello from F#! My name is {name}, the time is {time}"

let greetPerson name age =
  $"Hello, {name}, you are {age} years old."

let greet1 = greetPerson "John" 21
printfn "%s" greet1
