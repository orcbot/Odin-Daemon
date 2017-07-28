#ifndef SUB_H
#define SUB_H

#include "calc.h"
#include "../variables/variable.h"

class sub : public calc {
private:
	variable* operant1;
	variable* operant2;
	variable* result;

public:
	sub(variable*, variable*, variable*);
	~sub() { }
	
	void execute();
};

#endif