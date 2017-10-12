#include "mult.h"
#include "../errors/calculations_error.h"

mult::mult(variable* _op1, variable* _op2, variable* _result) {
	operant1 = _op1;
	operant2 = _op2;
	result = _result;
}

void mult::execute() {
	if (operant1->getRank() != 1 && operant1->getDimension(0)) {
		throw NotScalarError();
	}

	int finalRank = operant2->getRank();
	int finalDimensions[finalRank];
	int length = 1;

	for (int i = 0; i < finalRank; ++i) {
		finalDimensions[i] = operant2->getDimension(i);
		length *= finalDimensions[i];
	}

	double scalar = operant1->getValue(0);
	double finalValues[length];

	for (int i = 0; i < length; ++i)
	{
		finalValues[i] = scalar * operant2->getValue(i);
		//cout << i << " " << finalValues[i] << endl;
	}

	//strdelete result;
	result->setRank(finalRank);
	result->setDimensions(finalDimensions);
	result->setValues(finalValues);
}
