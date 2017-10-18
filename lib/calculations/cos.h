#ifndef COS_H
#define COS_H

#include "calc.h"
#include "../variables/variable.h"

class cosFunction : public calc {
private:
  variable* operant1;
  variable* result;

public:
  cosFunction(variable*, variable*);
  ~cosFunction() { }

  void execute();
};

#endif
