let addTenThenDouble theNumber =
  let answer = (theNumber + 10) * 2
  {| Answer = answer; Date = System.DateTime.UtcNow |}

let result = addTenThenDouble 10
printfn $"The answer is {result.Answer} and the date is {result.Date}"