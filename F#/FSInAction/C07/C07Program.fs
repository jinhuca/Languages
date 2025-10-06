// Listing 7.2
type TeamSummary = { Name: string; mutable AwayWins: int }
let summary = ResizeArray<TeamSummary>()

let output1 = [ 1; 2; 3; 4 ] |> List.map (fun x -> x.ToString())
let output2 = [ 1; 2; 3; 4 ] |> List.map (fun x -> x * 2 )
