type Customer = { Age: int }

let getAge c = c.Age
let classifyCustomer c = if c < 18 then "Child" else "Adult"

let getAgeOptional customer : int option = customer |> Option.map getAge

let customer1 = Some { Age = 23 }
let age1 = getAgeOptional customer1

let optionalClassification optionalCustomer = 
  optionalCustomer |> Option.map getAge |> Option.map classifyCustomer

let desc1 = optionalClassification customer1

let optionalClassificationShort optionalCustomer = 
  optionalCustomer |> Option.map (getAge >> classifyCustomer)
