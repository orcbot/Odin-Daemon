#include "abs.h"
#include "../errors/calculations_error.h"

absolute::absolute(variable* _op1, variable* _result) {
	operant1 = _op1;
	result = _result;
}

void absolute::execute() {
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
    if (operant1->getValue(i) < 0) {
      finalValues[i] = -1 * operant1->getValue(i);
    } else {
      finalValues[i] = operant1->getValue(i);
    }
	}

	//strdelete result;
	result->setRank(finalRank);
	result->setDimensions(finalDimensions);
	result->setValues(finalValues);
}
