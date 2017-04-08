# Searching Combos in games

In that example we have an hypothetical Scrabble game, with the following rules:

## Rules
** Movements **
The basic move for a player consists of 9 letters (from `a` to `z`). They can be repeated.

** Base Scoring ** 

- Words starting with `a`,`e`,`i`,`o` or `u` scores 6 points.
- `a` to `c` scores 1 point.
- `d` to `o` scores 2 points.
- `p` to `z` scores 3 points.
- Words ending with `p`,`q`,`r`,`w` or `z` scores 3 points.

** Combos **

- `ma`,`or`,`ed` multiplies *2 the base scoring.
- `nom`,`omg`,`lol`,`afk` multiplies *3 the base scoring.

** Super Combo **

The word 'codingame' gives 500 points.

Time to give a move: 100ms

## Using Monte Carlo

With Monte Carlo first we need the correct evaluation function. We simply code the rules inside an eval() function, that inputs a move and outputs an score.

Then we just need to randomize a lot of possible moves, evaluate them and keep the best.

@[Search Combo]({"stubs": ["combo/combo.cpp"], "command": "./combo/Combo"})

If you search closely, the Monte Carlo usually ends up with combos like `nomg`, because it's both `nom` and `omg` combo, and it's just 4 letters.

On the other hand, it's highly unlikely that Monte Carlo retrieves the SuperCombo. The SuperCombo is an exact set of ordered characters. And as Monte Carlo is pure random, the chances of getting a SuperCombo is 1 in 25^9.