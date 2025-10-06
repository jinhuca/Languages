// Listing 6.6 Working with namespace in F#
namespace Foo
type Order = { Name : string }

namespace Bar.Baz
type Customer = { Name : string; LastOrder : Foo.Order }

// Listing 6.7 Openning a namespace
open Foo
type CustomerTwo = { LastOrder : Order }
