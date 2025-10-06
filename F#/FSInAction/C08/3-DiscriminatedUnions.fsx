// Listing 8.8
type ContactMethod =
  | Email of address : string
  | Telephone of country : string * number : string
  | Post of
    {|
      Line1 : string
      Line2 : string
      City : string
      Country : string
    |}

let isaacEmail = Email "isaac@myemailaddress.com"
let isaacPhone = Telephone("UK", "020-8123-2345")
let isaacPost = Post {|
  Line1 = "1 Street"
  Line2 = "The Town"
  City = "The City"
  Country = "UK"
|}

type Customer = {
  Name : string
  Age : int
  ContactMethod : ContactMethod
}

let oneCustomer = {
  Name = "Isaac"
  Age = 30
  ContactMethod = isaacEmail
}

// Listing 8.9 Pattern matchinggg over a discriminated union
let message = "Discriminated Unions FTW!"

let description =
  match oneCustomer.ContactMethod with
  | Email address -> $"Emailing '{message}' to {address}."
  | Telephone(country, number) -> $"Calling {country}-{number} with the message '{message}'!"
  | Post postDetails -> $"Printing a letter with contents '{message}' to {postDetails.Line1} {postDetails.City} ..."

// listing 8.10 Modeling a nested (recursive) relationship with unions
type TelephoneNumber = 
  | Local of number : string
  | International of countryCode : string * number : string

type ContactMethodV2 =
  | Email of address : string
  | Telephone of country : string * number : string
  | Post of
    {|
      Line1 : string
      Line2 : string
      City : string
      Country : string
    |}
  | Sms of TelephoneNumber

let smsContact = Sms(Local "123-4567")

type CustomerV2 = {
  Name : string
  Age : int
  ContactMethod : ContactMethodV2
}

let sendTo customer message = 
  match customer.ContactMethod with
  | Sms(Local number) -> $"Texting local number {number}" 
  | Email _ 
  | Telephone _ 
  | Post _ -> "Other"
  | _ -> "Hmm"


