// Define a record type
type Person = {
  FirstName: string
  LastName: string
  Age: int
}

// Create an instance of the record
let isaac = {
  FirstName = "Isaac"
  LastName = "Abraham"
  Age = 42
}

// Consume record instance
let fullName = $"{isaac.FirstName} {isaac.LastName}"

// Listing 5.2 Constructing a nested recod
type Address = { 
  Line1 : string 
  Line2 : string 
  Town : string 
  Postcode : string
  Country : string
}

type PersonSimple = {
  Name : string * string
  Address : Address
}

let isaacNoAge = {
  Name = "Isaac", "Abraham"
  Address = failwith "Not Implemented"
}

// Exercise 5.2
type PersonWithDescription = {
  Name : string
  Age : int
  Description : string
}

let buildPerson (forename: string, surname: string, age: int) = {
  Name = $"{forename} {surname}"
  Age = age
  Description = if age < 18 then "child" else "adult"
}

// Listing 5.3 Using type inference for records within a function
let generatePerson theAddress =
  if theAddress.Country = "UK" then
    {
      Name = "Isaac", "Abraham"
      Address = theAddress
    }
  else
    {
      Name = "John", "Doe"
      Address = theAddress
    }

let theAddress = {
  Line1 = "1 Main Street"
  Line2 = ""
  Town = "London"
  Postcode = "SW1 1AA"
  Country = "UK"
}

// Listing 5.4 Using explicit type annotations when creating a record value
let isaacAddr : PersonSimple = {
  Name = "Isaac", "Abraham"
  Address = theAddress
}

let isaacAddrTwo = {
  PersonSimple.Name = "Isaac", "Abraham"
  Address = theAddress
}

// Listing 5.5 Using copy-and-update syntax to clone a record
let theAddressTwo = {
  Line1 = "1st Street"
  Line2 = "Apt. 1"
  Town = "London"
  Postcode = "SW1 1AA"
  Country = "UK"
}

let addressInDE = {
  theAddress with
    Town = "Berlin"
    Country = "DE"
}

// Listing 5.6 Equality checking
let isaacOne = {
  Name = "Isaac", "Abraham"
  Address = theAddress
}

let isaacTwo = {
  Name = "Isaac", "Abraham"
  Address = theAddress
}

let areTheyTheSame = (isaacOne = isaacTwo)

// Listing 5.7 Modeling similar types through composition
type ShortAddress = { Street : string; Country : string }
type Name = { Forename : string; Surname : string }

type Customer = {
  Name : Name
  Address : ShortAddress
  CreditRating : int
}

type Supplier = {
  Name : Name
  Address : ShortAddress
  Balance : decimal
  NextDueDate : System.DateTime
}

// Anonymous Records
let company = {|
  Name = "My Company Inc."
  Town = "The Town"
  Country = "UK"
  TaxNumber = 123456
|}

let companyWithBankDetails = {|
  company with
    AccountNumber = 123
    SortCode = 456
|}

// Listing 5.8
type PersonAnon = {
  Name : string * string
  Address : {|
    Line1 : string
    Line2 : string
    Town : string
    Country : string
  |}
}