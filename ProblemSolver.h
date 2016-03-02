#ifndef PROBLEM_SOLVER_H
#define PROBLEM_SOLVER_H


#include "NumberList.h"
#include "SolutionList.h"
#include "MathOperations.h"

class ProblemSolver {
public:
  void solveProblem(NumberList input);
  void printSolutions();
  void printBestSolution();
protected:
  // the target number for the final operation
  const static int finalSolutionTarget = 10;
  
  void solveStep(SolutionList& solutions, ProblemSolution& solution);
  void finishStep(SolutionList& solutions, ProblemSolution& solution);
/*  bool finalizeSolution(ProblemSolution& solution); */
  bool checkIfOperationIsFinal(int firstNum, 
			       int secondNum, 
			       MathOperations::Operation operation);
    
  SolutionList solutions;
};


#endif