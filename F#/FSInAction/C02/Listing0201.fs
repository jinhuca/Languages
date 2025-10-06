module Listing0201

open System

/// A train carriage can have a number of different features ...
type Feature = Quiet | Wifi | Toilet

/// A carriage can be either first or second class
type CarriageClass = First | Second

/// Carriage can be either for passengers or buffet carts
type carriageKind =
  | Passenger of CarriageClass
  | Buffet of {| ColdFood: bool; HotFood: bool |}

/// A carriage has a unique number on the train
type CarriageNumber = CarriageNumber of int

/// A carriage is composed of all of these things
type Carriage = 
  {
    Number: CarriageNumber
    Kind: carriageKind
    Features: Feature Set
    NumberOfSeats: int
  }

type TrainId = TrainId of string
type Station = Station of string
type Stop = Station * TimeOnly    /// Each stop is a station and a time of arrival

/// A train has a unique id, and a list of carriages. 
/// It always has an origin and destination, and a list of stops in between.
/// It *might* also have a station where the driver changes.
type Train = 
  {
    Id: TrainId
    Carriage: Carriage list
    Origin: Stop
    Stops: Stop list
    Destination: Stop
    DriverChange: Station option
  }
