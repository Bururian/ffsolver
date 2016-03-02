#ifndef MATH_OPERATIONS_H
#define MATH_OPERATIONS_H


#include <string>

class MathOperations {
public:
  enum Operation {
    addition = 0, subtraction, multiplication, division
  };
  const static int sizeOfOperation = 4;
  
  // Return an Operation as a std::string (e.g. "+" for addition)
  static std::string getOperationAsString(Operation operation);
  
  // Return true if performing the given Operation between firstNum and
  // secondNum, in that order, returns a legal result in our system
  static bool isOperationLegal(int firstNum, int secondNum, Operation operation);
  
  // Return the result of the given Operation between firstNum and secondNum
  static int doOperation(int firstNum, int secondNum, Operation operation);
};


#endif