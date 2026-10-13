// A variable is a symbolic name for a value. 
// You can think of it as a container that holds data. 
// In JavaScript, you can declare a variable using the `var`, `let`, or `const` keywords.
let x;                                  // Declare a variable named x.
// Values can be assigned to variables with an = sign.
x = 0;                                  // Now the variable x holds the value 0.

// JavaScript supports several types of values, including numbers, strings, and booleans.
x = 1                                   // Numbers.
console.log(x)                          // Output the value of x to the console.

x = 0.01                                // Numbers can be integers or reals.
console.log(x)                          // Output the value of x to the console.

x = "hello world"                       // Strings of text in quotation marks.
console.log(x)                          // Output the value of x to the console.

x = true                                // Boolean values can be true or false.
console.log(x)                          // Output the value of x to the console.

x = null                                // Null is a special value that represents "no value".
console.log(x)                          // Output the value of x to the console.

x = undefined                           // Undefined is a special value that represents "no value assigned".
console.log(x)                          // Output the value of x to the console.

// JavaScript's most important datatype is the object. 
// An object is a collection of properties, and a property is an association between a name 
// (or key) and a value. A value can be a function, which is then known as a method. Objects
// are used to store keyed collections of various data and more complex entities.
let book = {                            // Object is enclosed in curly braces {}.
  topic: "JavaScript",                  // The property "topic" has value "JavaScript".
  edition: 7                            // The property "edition" has value 7.
};                                      // The curly brace marks the end of the object.

// Access the properties of an object with . or []:
console.log(book.topic)                 // Returns "JavaScript"
console.log(book["edition"])            // Returns 7
book.author = "Flanagan"                // Create a new property named "author" and set its value.
console.log(book.author)                // Returns "Flanagan"
book.contents = {}                      // {} is an empty object with no properties

// Conditionally access properties with ?. (ES2020)
let y = book.contents?.ch01?.sect1      // Returns undefined (no error)
console.log(y)                          // 

// JavaScript also supports arrays (numerically indexed lists) of values:
let primes = [2, 3, 5, 7]               // Array is enclosed in square brackets [].
console.log(primes[0])                  // Returns 2.
console.log(primes.length)              // Returns 4.
z = primes[primes.length - 1]           // Get the last element of the array.
console.log(z)                          // Returns 7.
primes[4] = 9                           // Add a new element to the array.
primes[4] = 11                          // Change the value of an existing element.
let empty = []                          // [] is an empty array with no elements.
console.log(empty.length)               // => 0.

// Arrays and objects can hold other arrays and objects
let points = [                          // An array with 2 elements.
  { x: 0, y: 0 },                       // Each element is an object with x and y properties.
  { x: 1, y: 1 }
];
let data = {                            // An object with 2 properties
  trial1: [[1, 2], [3, 4]],             // Each property is an array of arrays.
  trial2: [[2, 3], [4, 5]]
};