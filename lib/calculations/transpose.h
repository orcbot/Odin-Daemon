#ifndef TRANSPOSE_H
#define TRANSPOSE_H

#include "calc.h"
#include "../variables/variable.h"

class transpose : public calc {
private:
  variable* operant1;
  variable* result;

public:
  transpose(variable*, variable*);
  ~transpose() { }

  void execute();
};

#endif
