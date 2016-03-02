#ifndef SOLUTION_STEP_H
#define SOLUTION_STEP_H


#include "MathOperations.h"

class SolutionStep {
public:
  SolutionStep(int cFirstNum, int cSecondNum, MathOperations::Operation cOperation)
    : firstNum(cFirstNum), secondNum(cSecondNum), operation(cOperation)
    { };
  
  int getFirstNum() const 
    { return firstNum; }
  int getSecondNum() const 
    { return secondNum; }
  MathOperations::Operation getOperation() const 
    { return operation; }
  
  void setFirstNum(int newFirstNum) { firstNum = newFirstNum; }
  void setSecondNum(int newSecondNum) { secondNum = newSecondNum; }
  void setOperation(MathOperations::Operation newOperation) {
    operation = newOperation;
  }
private:
  int firstNum;
  int secondNum;
  MathOperations::Operation operation;
};


#endif