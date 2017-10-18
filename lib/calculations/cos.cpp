#include "cos.h"
#include "../errors/calculations_error.h"
#include <cmath>

cosFunction::cosFunction(variable* _op1, variable* _result) {
  operant1 = _op1;
  result = _result;
}

void cosFunction::execute() {
  if ( !(operant1->getRank() == 1 && operant1->getDimension(0) == 1) ) {
    throw NotScalarError();
  }

  int finalRank = operant1->getRank();
  int finalDimensions[finalRank];
  int length = 1;

  for (int i = 0; i < finalRank; ++i) {
    finalDimensions[i] = operant1->getDimension(i);
  }

  double finalValues[length];

  finalValues[0] = cos(operant1->getValue(0));

  //strdelete result;
  result->setRank(finalRank);
  result->setDimensions(finalDimensions);
  result->setValues(finalValues);
}
