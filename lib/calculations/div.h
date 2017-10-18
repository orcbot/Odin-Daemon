#ifndef DIV_H
#define DIV_H

#include "calc.h"
#include "../variables/variable.h"

class sdiv : public calc {
private:
	variable* operant1;
	variable* operant2;
	variable* result;

public:
	sdiv(variable*, variable*, variable*);
	~sdiv() { }

	void execute();
};

#endif
