#ifndef MUL_H
#define MUL_H

#include "calc.h"
#include "../variables/variable.h"

class mul : public calc {
private:
	variable* operant1;
	variable* operant2;
	variable* result;

public:
	mul(variable*, variable*, variable*);
	~mul() { }
	
	void execute();
};

#endif