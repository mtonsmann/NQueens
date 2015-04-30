Marcus Tonsmann
Data Structures Spring 2015
N-Queens Extra Credit Assignment

I went about solving this assignment slighty differently than normal. Instead
of using recursion to solve for the number of possible solutions, I wrote a
program that utilizes an Iterative Repair algorithm to solve for a possible
solution. So, even though it does not solve for all possible solutions, it is
capable producing a solution for very high values of N. The only limit to how
high of an N value it is capable of solving is how fast is can navigate the 
Vector of Vectors that is used to represent the chess board. Since the Big O
for this is O(n^2), it quickly gets more difficult to navigate the data 
structure, and although solutions get "easier" to find, the program slows
significantly at n values > 50. The program is still capable of finding
solutions for N = 65 in less than 1 second fairly regularly. If I chose a 
different data structure to represent my board, it may be possible to solve 
for much higher N values even faster. Since this program utilizes a greedy 
algorithm, it can solve for very large data sets very fast, but can also get 
unlucky with the random set up, which is why we allow a restart after a 
certain number of steps. If the program has a poor board set-up or is stuck,
it will reach the max steps allowed and restart. When prompted for this 
number, a integer around n is usualy good, but great speed improvements can
be made if the value is bigger for small values of N, and smaller for large
values of N. This is because there are more solutions for large N values,
so it is possible to solve them in less steps.

This assignment helped me learn a lot about program and algorithm design,
as well as the downsides to certain data structures and even introduced me
to some high level agorithm design concepts, such as greedy algorithms.

1) People who helped: Loki Hondorf

2) I liked how open ended the approach was allowed to be. I disliked that
I misread the assignment and thought you just needed to find "a solution"

3) Around 10+ hours. Could be much greater... track of time was lost.
