#ifndef SIN_H
#define SIN_H

#include "calc.h"
#include "../variables/variable.h"

class sinFunction : public calc {
private:
  variable* operant1;
  variable* result;

public:
  sinFunction(variable*, variable*);
  ~sinFunction() { }

  void execute();
};

#endif
