module Listing0407

let drive gas distance =
  if distance = "far" then gas / 2.0
  elif distance = "medium" then gas - 10.0
  else gas - 1.0

let gas = 100.0
let firstState = drive gas "far"
let secondState = drive firstState "medium"
let thirdState = drive secondState "near"