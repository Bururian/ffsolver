#include "ProblemSolution.h"
#include "SolutionStep.h"
#include "MathOperations.h"
#include <iostream>

void ProblemSolution::addStep(
  int firstNum, 
  int secondNum, 
  MathOperations::Operation operation
  ) {
  steps.push_back(SolutionStep(firstNum, secondNum, operation));
}

void ProblemSolution::extendExistingSolution(
    const ProblemSolution& existingSolution,
    MathOperations::Operation operation,
    int firstIndex,
    int secondIndex
  ) {
  // copy existing steps
  steps = existingSolution.steps;
  
  // copy all remaining numbers not used by the new solution
  copyUnusedRemaining(existingSolution, firstIndex, secondIndex);
  
  // perform operation and add result to remaining
  remaining.push_back(MathOperations::doOperation(
	  existingSolution.remaining[firstIndex],
	  existingSolution.remaining[secondIndex],
	  operation));
  
  // record performed step
  addStep(existingSolution.remaining[firstIndex],
	  existingSolution.remaining[secondIndex],
	  operation);
}

void ProblemSolution::copyUnusedRemaining(
    const ProblemSolution& existingSolution,
    int firstIndex,
    int secondIndex
       ) {
  for (int i = 0; i < existingSolution.remaining.size(); i++) {
    // copy only unused indices
    if (i != firstIndex && i != secondIndex) {
      remaining.push_back(existingSolution.remaining[i]);
    }
  }
}

int ProblemSolution::getScore() const {
  int score = 0;
  
  for (SolutionStepList::const_iterator it = steps.begin();
       it != steps.end();
       it++) {
    int result = MathOperations::doOperation(it->getFirstNum(),
					     it->getSecondNum(),
					     it->getOperation());
    
    // negative results don't count against score
    if (result > 0) {
      score += result;
    }
  }
  
  return score;
}

void ProblemSolution::printRemaining() const {
  for (RemainingList::const_iterator it = remaining.begin();
       it != remaining.end();
       it++) {
    std::cout << (*it) << " ";
  }
  std::cout  << std::endl;
}

void ProblemSolution::printSteps() const {
  for (SolutionStepList::const_iterator sit = steps.begin();
    sit != steps.end();
    sit++) {
    
    std::cout << '\t';
    std::cout << sit->getFirstNum() << " ";
    std::cout << MathOperations::getOperationAsString(sit->getOperation()) << " ";
    std::cout << sit->getSecondNum() << std::endl;
    
  }
}

void ProblemSolution::print() const {
  
  std::cout << "Remaining: ";
  
  printRemaining();
  
  std::cout << "Steps: " << std::endl;
  
  printSteps();
}
