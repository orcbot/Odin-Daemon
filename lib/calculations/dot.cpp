#include "dot.h"
#include "../errors/calculations_error.h"

dot::dot(variable* _op1, variable* _op2, variable* _result) {
	operant1 = _op1;
	operant2 = _op2;
	result = _result;
}

void dot::execute() {
	if (operant1->getRank() != 1 && operant2->getRank() != 1) {
		throw NotVectorError();
	}

	if (operant1->getDimension(0) != operant2->getDimension(0)) {
		throw DimensionsNotEqualError();
	}

	int finalDimensions[1];
	finalDimensions[0] = 1;
	double finalValues[1];
	finalValues[0] = 0;

	for (int i = 0; i < operant1->getDimension(0); ++i) {
		double temp = operant1->getValue(i) * operant2->getValue(i);
		finalValues[0] += temp;
	}

	result->setRank(1);
	result->setDimensions(finalDimensions);
	result->setValues(finalValues);
}
