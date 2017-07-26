#ifndef CALC_H
#define CALC_H

class calc {
public:
	calc();
	~calc();
	
	virtual void execute() = 0;	
};

#endif