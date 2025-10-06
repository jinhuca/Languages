// Tuple basics
let name = "isaac", "abraham"
let firstName secondName = name

// Create record
type Person =
  {
    FirstName : string
    LastName : string
    Age : int
  }

type Address = { Line1 : string; Line2 : string }

// Instantiate a record
let isaac =
  {
    FirstName = "Isaac"
    LastName = "Abraham"
    Age = 42
  }

// Consume a record
let fullName = $"{isaac.FirstName} {isaac.LastName}"



