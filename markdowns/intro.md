# What is Monte Carlo Method?

I won't go into boring mathematical stuff. 
Monte Carlo Method is named after the Monte Carlo Casino, as a clear reference to its random nature. 
So the Method is just testing a lot of possible random solutions and keep the best. 

In pseudo code that means:

```csharp
int bestScore = -99999999;
var bestmoves;
while (there_is_time){
  var tmpMoves = create_random_moves();
  simulate_those_moves(tmpMoves);
  tmpScore = evaluate_that_outcome();
  if (tmpScore > bestScore) 
     then update bestScore and bestmoves;
}
```

As you see, the three steps of the loop are:

- Generate random solutions: Try to use good pseudorandom numbers, or the random module your language has (but it's slower).
- Simulate the state by applying those moves: It's important that your simulation is accurate to the problem.
- Evaluate the simulated state: If it's a car racing game, being 1st should be scored high, also being on track, being facing on the right direction, etc.

That's the general way to use Monte Carlo. On the next lesson we will learn about how to calculate 2D areas with Monte Carlo.