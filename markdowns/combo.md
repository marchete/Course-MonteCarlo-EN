# Searching Combos in games

In that example we have an hypothetical Scrabble game, with the following rules:

## Rules
** Movements **
The basic move for a player consists of 9 letters (from `a` to `z`). They can be repeated.

** Base Scoring ** 
-`a` to `c` scores 1 point.
-`d` to `o` scores 2 points.
-`p` to `z` scores 3 points.

** Combos **
-`ma`,`or`,`ed` multiplies *2 the base scoring.
-`nom` multiplies *3 the base scoring.

** Super Combo **
The word 'codingame' gives 10000 points.
 
Time to give a move: 100ms
 
## Using Monte Carlo

With Monte Carlo first we need the correct evaluation function. We simply code the rules inside an eval() function, that inputs a move and outputs an score.

Then we just need to randomize a lot of possible moves, evaluate them and keep the best.

**TODO: Add Exercise**