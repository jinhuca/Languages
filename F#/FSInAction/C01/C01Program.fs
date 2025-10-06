let addTenThenDouble theNumber =
  let answer = (theNumber + 10) * 2
  {| Answer = answer; Date = System.DateTime.UtcNow |}

let result = addTenThenDouble 10
