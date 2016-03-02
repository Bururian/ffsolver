#include "ProblemSolver.h"
#include "MathOperations.h"
#include <iostream>

void ProblemSolver::solveProblem(NumberList input) {
  ProblemSolution baseSolution(input);
  solveStep(solutions, baseSolution);
}

void ProblemSolver::printSolutions() {
  
  if (solutions.empty()) {
    std::cout << "No solution" << std::endl;
    return;
  }
  
  int num = 1;
  
  for (SolutionList::const_iterator it = solutions.begin();
       it != solutions.end();
       it++) {
    
    std::cout << "Solution " << num << ", score " << it->getScore() << ":" << std::endl;
  
    it->printSteps();
    
    num++;
  }
}

void ProblemSolver::printBestSolution() {
  if (solutions.empty()) {
    std::cout << "No solution" << std::endl;
    return;
  }
  
  SolutionList::const_iterator bestSolution = solutions.begin();
  int bestNum = 1;
  
  int num = 1;
  for (SolutionList::const_iterator it = solutions.begin();
       it != solutions.end();
       it++) {
    if (it->getScore() > bestSolution->getScore()) {
      bestSolution = it;
      bestNum = num;
    }
    num++;
  }
  
  std::cout << "Solution " << bestNum << " of " << solutions.size() << ", score " 
      << bestSolution->getScore() << ":" << std::endl;
  bestSolution->printSteps();
  
}

void ProblemSolver::solveStep(SolutionList& solutions, ProblemSolution& solution) {
  
//  solution.print();
  
  // termination condition: 2 numbers remaining in solution
  if (solution.getRemaining().size() == 2) {
    finishStep(solutions, solution);
    return;
  }
  
  // produce putative solution by performing brute force search
  // on remaining numbers
  
  for (int i = 0; i < solution.getRemaining().size(); i++) {
    for (int j = 0; j < solution.getRemaining().size(); j++) {
      // can't use same number twice
      if (i == j) continue;
      
      int firstNum = solution.getRemaining()[i];
      int secondNum = solution.getRemaining()[j];
      
      // create new solutions based on each possible operation
      // between the target numbers
      
      for (int k = 0; k < MathOperations::sizeOfOperation; k++) {
	MathOperations::Operation operation = static_cast<MathOperations::Operation>(k);
	
	// check if operation is legal and skip it if it is not
	if (!MathOperations::isOperationLegal(firstNum, secondNum, operation)) {
	  continue;
	}
	
	ProblemSolution newSolution;
	newSolution.extendExistingSolution(solution, operation, i, j);
	
	// recurse on newly generated solution
	solveStep(solutions, newSolution);
      }
    }
  }
}

void ProblemSolver::finishStep(SolutionList& solutions, ProblemSolution& solution) {
/*  if (finalizeSolution(solution)) {
    solutions.push_back(solution);
  } */
  
//  solution.print();
  
  // solution cannot be final if there are not 2 numbers remaining
  if (solution.getRemaining().size() != 2) {
    // should probably throw here
    return;
  }
  
  for (int i = 0; i < MathOperations::sizeOfOperation; i++) {
    int firstNum = solution.getRemaining()[0];
    int secondNum = solution.getRemaining()[1];
    MathOperations::Operation operation = static_cast<MathOperations::Operation>(i);
    
    // check whether performing the operation on the final numbers in
    // either order will result in the desired solution
    if (checkIfOperationIsFinal(firstNum,
				secondNum,
				operation)) {
      solution.addStep(firstNum,
		       secondNum,
		       operation);
      solution.clearRemaining();
      solutions.push_back(solution);
    }
    else if (checkIfOperationIsFinal(secondNum,
				     firstNum,
				     operation)) {
      solution.addStep(secondNum,
		       firstNum,
		       operation);
      solution.clearRemaining();
      solutions.push_back(solution);
    }
  }
}

/*bool ProblemSolver::finalizeSolution(ProblemSolution& solution) {
  
//  solution.print();
  
  // solution cannot be final if there are not 2 numbers remaining
  if (solution.getRemaining().size() != 2) {
    // should probably throw here
    return false;
  }
  
  for (int i = 0; i < MathOperations::sizeOfOperation; i++) {
    int firstNum = solution.getRemaining()[0];
    int secondNum = solution.getRemaining()[1];
    MathOperations::Operation operation = static_cast<MathOperations::Operation>(i);
    
    if (firstNum == 6 && secondNum == 4) { solution.print(); }
    
    // check whether performing the operation on the final numbers in
    // either order will result in the desired solution
    if (checkIfOperationIsFinal(firstNum,
				secondNum,
				operation)) {
      solution.addStep(firstNum,
		       secondNum,
		       operation);
      solution.clearRemaining();
    }
    else if (checkIfOperationIsFinal(secondNum,
				     firstNum,
				     operation)) {
      solution.addStep(secondNum,
		       firstNum,
		       operation);
      solution.clearRemaining();
    }
  }
} */

bool ProblemSolver::checkIfOperationIsFinal(int firstNum, 
			      int secondNum, 
			      MathOperations::Operation operation) {
  // illegal operations aren't allowed
  if (!MathOperations::isOperationLegal(firstNum, secondNum, operation)) {
    return false;
  }
  
//  std::cout << firstNum << " " << secondNum << " " << operation << std::endl;
  
  return (MathOperations::doOperation(firstNum, secondNum, operation)
    == finalSolutionTarget);
}