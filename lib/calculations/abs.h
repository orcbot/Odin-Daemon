#ifndef ABS_H
#define ABS_H

#include "calc.h"
#include "../variables/variable.h"

class absolute : public calc {
private:
	variable* operant1;
	variable* result;

public:
	absolute(variable*, variable*);
	~absolute() { }

	void execute();
};

#endif
