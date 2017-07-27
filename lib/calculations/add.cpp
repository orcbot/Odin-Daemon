#include "add.h"

add::add(variable* _op1, variable* _op2, variable* _result) {
	operant1 = _op1;
	operant2 = _op2;
	result = _result;
}

variable* add::execute() {
	if (operant1->getRank() != operant2->getRank()) {
		throw "Error: Bitch these ranks aren't even the same";
	}

	string finalName = result->getName();
	bool finalSave = result->getSave();
	int finalRank = operant1->getRank();
	int finalDimensions[finalRank];
	int length = 1;

	for (int i = 0; i < finalRank; ++i) {
		if (operant1->getDimension(i) != operant2->getDimension(i)) {
			throw "Error: Bitch these dimensions aren't even the same";
		}
		finalDimensions[i] = operant1->getDimension(i);
		length *= finalDimensions[i];
	}

	double finalValues[length];

	for (int i = 0; i < length; ++i)
	{
		finalValues[i] = operant1->getValue(i) + operant2->getValue(i);
		cout << i << " " << finalValues[i] << endl;
	}

	//strdelete result;
	variable* returnVal = new variable();
	returnVal->setName(finalName);
	returnVal->setSave(finalSave);
	returnVal->setRank(finalRank);
	returnVal->setDimensions(finalDimensions);
	returnVal->setValues(finalValues);

	return returnVal;
}