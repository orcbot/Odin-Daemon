#ifndef VAR_H
#define VAR_H

#include <string.h>
#include <iostream>
using namespace std;

class variable {
public:
	variable(string);
	~variable();
	string getName();
	int getRank();
	int getDimension(int);
	double getValue(int);
	bool getSave();
	void printVar();
private:
	string name;
	int rank;
	int *dimensions;	
	double *values;
	bool save;
};

#endif