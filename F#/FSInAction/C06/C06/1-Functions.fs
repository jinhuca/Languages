// Listing 6.1
let foo (x : int) (y : int) : unit = ()

// Listing 6.2
let add firstNumber secondNumber = firstNumber + secondNumber
let addFive = add 5
let fifteen = addFive 10

// Exercise 6.1
let addTen = add 10
let multiply firstNumber secondNumber = firstNumber * secondNumber
let timesTwo = multiply 2
let addTenAndDouble number = timesTwo (addTen number)

// Partially applying functions
type LetterType =
  | Welcome = 0
  | PaymentOverdue = 1

let sendEmail customerAddress letterType = ()
let sendEmailToFred = sendEmail "fred@email.com"
sendEmailToFred LetterType.Welcome
sendEmailToFred LetterType.PaymentOverdue

let sendEmailManyArgs sender letterType emailAddress postDate = ()
let sendOfficeWelcome = sendEmailManyArgs "office@firm.com" LetterType.Welcome
sendOfficeWelcome "fred@email.com" System.DateTime.UtcNow
sendOfficeWelcome "joanne@email.com" (System.DateTime.UtcNow.AddDays 1.)

// Listing 6.3 Manually threading values in a chain of functions
let firstValue = add 5 10
let secondValue = add firstValue 7
let finalValue = multiply secondValue 2
let finalValueChained = multiply (add (add 5 10) 7) 2

// Listing 6.4 Chaining function calls using the pipeline operator
let pipelineCalcSingleLine = 10 |> add 5 |> add 7 |> multiply 2
let pipelineCalcMultipleLine =
  10
  |> add 5
  |> add 7
  |> multiply 2

// Listing 6.5 A pipeline to send an email to a customer
let customerId = ()
let loadFromDb () = ()
let reviewCustomer () = ()

type EmailTemplate =
    | Overdue = 1
    | Welcome = 2

let createEmail template () = ()
let send () = ()

customerId
  |> loadFromDb
  |> reviewCustomer
  |> createEmail EmailTemplate.Overdue
  |> send

// Exercise 6.2
let drive distance gas =
    if distance > 50 then gas / 2.0
    elif distance > 25 then gas - 10.0
    elif distance > 0 then gas - 1.0
    else gas

100.0 |> drive 55 |> drive 26 |> drive 1
