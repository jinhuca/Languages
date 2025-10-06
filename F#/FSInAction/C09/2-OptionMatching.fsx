type Customer = { Age : int }

let getAge customer : int option =
  match customer with
  | Some c -> Some c.Age
  | None -> None

let classifyCustomer c =
  if c < 18 then "Child" else "Adult"

let c1 = { Age = 10 }

