#ifndef ADD_H
#define ADD_H

#include "calc.h"
#include "../variables/variable.h"

class add : public calc {
private:
	variable* operant1;
	variable* operant2;
	variable* result;

public:
	add(variable*, variable*, variable*);
	~add() { }
	
	void execute();
};

#endif