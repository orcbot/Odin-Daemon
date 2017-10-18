#include "transpose.h"
#include "../errors/calculations_error.h"

transpose::transpose(variable* _op1, variable* _result) {
  operant1 = _op1;
  result = _result;
}

void transpose::execute() {
  int finalRank = operant1->getRank();
  int finalDimensions[finalRank];
  int length = 1;

  for (int i = 0; i < finalRank; ++i) {
    finalDimensions[i] = operant1->getDimension(i);
    length *= finalDimensions[i];
  }

  double finalValues[length];

  for (int i = 0; i < length; ++i)
  {
    int index = length - (1 + i);
    finalValues[i] = operant1->getValue(index);
  }

  //strdelete result;
  result->setRank(finalRank);
  result->setDimensions(finalDimensions);
  result->setValues(finalValues);
}
