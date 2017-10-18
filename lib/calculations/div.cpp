#include "div.h"
#include "../errors/calculations_error.h"

sdiv::sdiv(variable* _op1, variable* _op2, variable* _result) {
	operant1 = _op1;
	operant2 = _op2;
	result = _result;
}

void sdiv::execute() {
	if (!(operant1->getRank() == 1 && operant1->getDimension(0) == 1) && !(operant2->getRank() == 1 && operant2->getDimension(0) == 1)) {
		throw NotScalarError();
	}

	if (operant1->getRank() == 1 && operant1->getDimension(0) == 1) {
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
			finalValues[i] = operant2->getValue(i) / scalar;
		}

		//set result
		result->setRank(finalRank);
		result->setDimensions(finalDimensions);
		result->setValues(finalValues);
	} else {
		int finalRank = operant1->getRank();
		int finalDimensions[finalRank];
		int length = 1;

		for (int i = 0; i < finalRank; ++i) {
			finalDimensions[i] = operant1->getDimension(i);
			length *= finalDimensions[i];
		}

		double scalar = operant2->getValue(0);
		double finalValues[length];

		for (int i = 0; i < length; ++i)
		{
			finalValues[i] = operant1->getValue(i) / scalar;
		}

		//set result
		result->setRank(finalRank);
		result->setDimensions(finalDimensions);
		result->setValues(finalValues);
	}
}
