#ifndef CALC_H
#define CALC_H

#include "../variables/variable.h"

class calc {
public:
	virtual variable* execute() = 0;	
};

#endif