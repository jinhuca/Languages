// Option.bind

type CustomerOptionalAge = { Name: string; Age: int option }
let getAge c = c.Age
let theCustomer = Some { Name = "Isaac"; Age = Some 42 }
let optionalAgeDoubleOpt: int option option = theCustomer |> Option.map getAge
let optionalAge: int option = theCustomer |> Option.bind getAge

let optionalAgePatternMatch =
  match theCustomer with
  | Some theCustomer ->
      match theCustomer.Age with
      | Some age -> Some age
      | None -> None
  | None -> None
