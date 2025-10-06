open System
let optionalName: string option = null |> Option.ofObj
let optionalNameTwo = "Isaac" |> Option.ofObj
let optionalAgeTwo = Nullable 123 |> Option.ofNullable

