#include "MathOperations.h"
#include <string>
#include <iostream>

std::string MathOperations::getOperationAsString(Operation operation) {
  switch (operation) {
    case addition:
      return std::string("+");
    case subtraction:
      return std::string("-");
    case multiplication:
      return std::string("*");
    case division:
      return std::string("/");
  }
}

bool MathOperations::isOperationLegal(int firstNum, int secondNum, Operation operation) {
  if (operation == division) {
    // disallow division by zero
    if (secondNum == 0) {
      return false; 
    }
    
    // disallow division resulting in nonzero remainder
    if (firstNum % secondNum != 0) {
      return false;
    }
  }
  
  return true;
}

int MathOperations::doOperation(int firstNum, int secondNum, Operation operation) {
  switch (operation) {
    case addition:
      return firstNum + secondNum;
    case subtraction:
      return firstNum - secondNum;
    case multiplication:
      return firstNum * secondNum;
    case division:
      return firstNum / secondNum;
  }
}