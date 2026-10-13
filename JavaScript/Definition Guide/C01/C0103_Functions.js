// Functions are parameterized blocks of JavaScript code that we can invoke.
function plus1(x) {             // Define a function named "plus1" with parameter "x"
  return x + 1;                 // Return a value one later than the value passed in
}                               // Functions are enclosed in curly braces

let r = plus1(5);               // Call the function with argument 5 and store the return value in r
console.log(r);                 // Output the value of r to the console.

let square = function(x) {      // Functions are values and can be assigned to vars
  return x * x;                 // Compute the function's value
}                               // Semicolon marks the end of the assignment.

let y = 5
let r1 = square(plus1(y))       // invoke two functions in one expression
console.info(r1)

