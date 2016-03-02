#ifndef PROBLEM_SOLUTION_H
#define PROBLEM_SOLUTION_H


#include "NumberList.h"
#include "SolutionStepList.h"
#include "RemainingList.h"
#include "MathOperations.h"

class ProblemSolution {
public:
  
  ProblemSolution() { };
  ProblemSolution(const NumberList& problemInput) {
    remaining = problemInput;
  }
  
  const SolutionStepList& getSteps() const 
    { return steps; }
  const RemainingList& getRemaining() const 
    { return remaining; }
    
  void clearSteps() { steps.clear(); }
  void clearRemaining() { remaining.clear(); }
  
  
  void addStep(
    int firstNum, 
    int secondNum, 
    MathOperations::Operation operation
	);
  
  void extendExistingSolution(
    const ProblemSolution& existingSolution,
    MathOperations::Operation operation,
    int firstIndex,
    int secondIndex
       );
  
  void copyUnusedRemaining(
    const ProblemSolution& existingSolution,
    int firstIndex,
    int secondIndex
       );
  
  int getScore() const;
  
  void printRemaining() const;
  void printSteps() const;
  void print() const;
  
protected:
  SolutionStepList steps;
  RemainingList remaining;
};


#endif