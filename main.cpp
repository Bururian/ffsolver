/* A simple brute force solver for the "Scholar Bear's Math Game" minigame in 
 * Final Fantasy: The 4 Heroes of Light. Enter the four numbers the game 
 * gives you into standard input, and the program will compute the highest-
 * scoring series of operations or report that there's no solution.
 * To quit, enter a 0.
 * 
 * Note that the most reliable way to increase your score seems to be to
 * keep passing over and over. The game generates enough unsolvable
 * problems that the 20-point bonuses tend to outweigh the 5-point
 * penalties. */

// How many numbers of input to be used per problem,
// which is always 4 in the game
const static int numberOfInputs = 4;

#include <iostream>
#include "NumberList.h"
#include "ProblemSolver.h"

int main() {
   do {
  
    NumberList input;
    
    for (int i = 0; i < numberOfInputs; i++) {
      int n;
      std::cin >> n;
      input.push_back(n);
      
      // quit if any number is 0
      if (n == 0) return 0;
    }
    
    ProblemSolver solver;
    solver.solveProblem(input);
    solver.printBestSolution();
    
   } while (true);
   
}
