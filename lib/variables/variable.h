#ifndef VAR_H
#define VAR_H

#include <string.h>
#include <iostream>
using namespace std;

class variable {
  public:
  	variable();
  	variable(string);
  	~variable();

  	/**
  	* Getters
  	*
  	**/
  	string getName();
  	int getRank();
  	int getDimension(int);
  	double getValue(int);
  	bool getSave();

  	/**
  	* Setters
  	*
  	**/
  	void setName(string);
  	void setRank(int);
  	void setDimensions(int[]);
  	void setValues(double[]);
  	void setSave(bool);

  	void printVar();
  	string toJSON();
  private:
  	string name;
  	int rank;
  	int *dimensions;
  	double *values;
  	bool save;
    int valuesLength;
};

#endif
