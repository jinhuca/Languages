module Listing0403

let describeAge age =
  let ageDescription =
    if age < 18 then "Child"
    elif age < 65 then "Adult"
    else "OAP"
  let greeting = "Hello"
  $"{greeting}! You are a '{ageDescription}'"

let r1 = describeAge 33
