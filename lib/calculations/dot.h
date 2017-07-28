#ifndef DOT_H
#define DOT_H

#include "calc.h"
#include "../variables/variable.h"

class dot : public calc {
private:
	variable* operant1;
	variable* operant2;
	variable* result;

public:
	dot(variable*, variable*, variable*);
	~dot() { }
	
	void execute();
};

#endif