#ifndef SQRT_H
#define SQRT_H

#include "calc.h"
#include "../variables/variable.h"

class squareRoot : public calc {
private:
  variable* operant1;
  variable* result;

public:
  squareRoot(variable*, variable*);
  ~squareRoot() { }

  void execute();
};

#endif
