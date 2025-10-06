let i = 10
let j : int = 12

let myInt = 10
let myString = "Hello"
let myFloat = 1.23
let myDate = System.DateTime.Now

let calculateGroup age =
  if age < 18 then "Child"
  elif age < 65 then "Adult"
  else "Pensioner"

let sayHello someValue =
  let group =
    if someValue < 10.0 then calculateGroup 15
    else calculateGroup 35
  "Hello " + group

let r1 = sayHello 11.5

let addThreeDays (theDate : System.DateTime) =
  theDate.AddDays 3

let r2 = addThreeDays System.DateTime.Now

let addYearAndThreeDays theDate =
  let threeDaysForward = addThreeDays theDate
  theDate.AddYears 1

let r3 = addYearAndThreeDays System.DateTime.Now
