#ifndef MUL_H
#define MUL_H

#include "calc.h"
#include "../variables/variable.h"

class mult : public calc {
private:
	variable* operant1;
	variable* operant2;
	variable* result;

public:
	mult(variable*, variable*, variable*);
	~mult() { }
	
	void execute();
};

#endif