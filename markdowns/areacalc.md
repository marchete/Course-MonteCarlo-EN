# Calculating areas with Monte Carlo

Areas of single primitives (rectangles, circles) are easy to calculate. There are mathematical functions to calculate it in an accurate way, with high precision.

But what happens when you have many shapes and you want to calculate the following?:

- The union of those shapes.
- The intersection of those shapes.
- The subtraction of n shapes from one main shape.

In these cases the area calculation is not trivial. You need to play with geometry, and things get more complicated the more shapes you have.

I'll show you how to solve this by using Monte Carlo experiments.
You can have 2, 3 or 1000 shapes, the solution will be the same.

## Setting up a reference area.

We'll create an area, a canvas of an arbitrary size. This area is our `Reference Area`.
It will be a rectangle, so we know that its area is just `Ref_Width*Ref_Height`.

## Placing shapes inside the reference area

We need to place all our shapes inside that `Reference Area`, they can't be outside because our Monte Carlo simulation will randomly test only inside that boundaries.

## Do the Monte Carlo experiments

Now, applying Monte Carlo is simple. 
The pseudocode is:
```csharp
 var areacount = 0;
 for (N simulations){
   pick up a random point from inside the reference area;
   check if it is inside the shape (taking into account union, intersection or subtraction);
   if it is, add 1 to areacount;
 }
```
Here we used a fixed number of simulations. This can be changed to be limited in time (like 100ms), then `N` will be increasing until you have no more time.

## Calculate the estimated area
If you have `areacount` points that are inside shapes, and you total tests were `N`, then in theory your area is the `areacount/N`% of the `Reference Area`.
```csharp
 var RefArea = Ref_Width*Ref_Height;
 var PercentageFilled = areacount/N;
 var MonteCarloArea = RefArea * PercentageFilled;
```

## And that's it!!!
As you see, Monte Carlo is absurdly simple.

>**NOTE**: Monte Carlo doesn't guarantee an exact solution, it's an approximation to the real area. But the accuracy can be very good (>99.95%) with enough tests.

On next lessons will see some live examples of area calculations: unions, intersections and subtractions.