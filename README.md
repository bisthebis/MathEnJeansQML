# "Sens dessus dessous"

"Sens dessus dessous" is my implementation of the puzzle game on which I worked at school with some friends during the year 2015-2016 in the context of the MATh.en.JEANS project (https://www.mathenjeans.fr/)
It is a game consisting of a 2D grid filled of tokens with a white face and a black face. 
At the beginning, all the tokens show the white face, and the player has to flip all of them so that they go black. 
It can be done with a simple rule : you can flip any coin in the board, but when you do it, you have to flip its (up to 4) neighbours.

Our task was, among other things, to find if all boards (with varying dimensions) have at least one solution 
(which looks to be true from an empiric point of view, but we couldn't prove it !), 
to look for a possible relationship between the dimensions and the numer of solutions, and to find the best procedure to automatically find a solution.

## How it is solved (by computer)

If you look closely at the rules of the game, you can see that : 
- No matter in what order you do your moves, the result will be the same with the same moves.
- Choosing (by "choosing", I mean "those that we decide to flip" and not the neighbours automatically flipped) 2 times to flip the same token is the same as doing nothing.

Thus, we can represent a list of moves as a list of booleans : for each token, we want to know if we want to flip it or not. 
Because of this, a brute force algorithm has to try 2 exponent (W * H) combinations, with W and H the dimensions of the board,
which is awfully long with non trivial dimensions.

What we found out later was that for every arbitrary combination on the first line (or row), 
there was at most 1 version of the next line that would match. 
With this knowledge, we can use a better brute force algortihm, where the complexity is only of 2 exponent (min(W, H)).

## Features of the implementation

This implementation is a playable game with the addition of automatic solving. You can play as you wish and experiment, 
or have the computer find the solutions for you. (Well, unless you have a supercomputer with limitless RAM, don't attempt for grid size bigger than 16x16)
It is written in C++ with Qt Quick, so it's cross platform; as long as you build it yourself, you can run it on Windows, MacOS, Linux, Android and iOS.

## Pictures

![Ingame picture](https://raw.githubusercontent.com/bisthebis/MathEnJeansQML/master/img/pic1.png)
![Ingame picture](https://raw.githubusercontent.com/bisthebis/MathEnJeansQML/master/img/pic2.png)
![Ingame picture](https://raw.githubusercontent.com/bisthebis/MathEnJeansQML/master/img/pic3.png)
![Ingame picture](https://raw.githubusercontent.com/bisthebis/MathEnJeansQML/master/img/pic4.png)
