// Consuming Tasks
open System.IO
open System.Threading.Tasks

File.WriteAllText("foo.txt", "Hello, world")
let text : string = File.ReadAllText "foo.txt"
let textAsync : Task<string> = File.ReadAllTextAsync "foo.txt"

let theText : string = textAsync.Result
