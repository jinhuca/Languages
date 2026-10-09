open System

type Feature = Quiet | Wifi | Toilet
type CarriageClass = First | Second

type CarriageKind =
    | Passenger of CarriageClass
    | Buffet of {| ColdFood : bool; HotFood : bool|}

type CarriageNumber = CarriageNumber of int

type Carriage = {
    Number : CarriageNumber
    Kind : CarriageKind
    Features : Feature Set
    NumberOfSeats : int
}

type TrainId = TrainId of string
type Station = Station of string
type Stop = Station * TimeOnly

type train = {
    Id : TrainId
    Carriages : Carriage list
    Origin : Stop
    Stops : Stop list
    Destination : Stop
    DriverChange: Station option
}