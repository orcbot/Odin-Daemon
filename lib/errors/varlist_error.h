#ifndef VARLIST_ERROR_H
#define VARLIST_ERROR_H

#include "error.h"

class VariableNotFoundError : public error {
public:
  VariableNotFoundError() { };
  ~VariableNotFoundError() { };

  virtual char* getMessage() { return NULL; }
  virtual char* getResponse() { return NULL; }
};

class VariableAlreadyExistsError : public error {
public:
  VariableAlreadyExistsError() { };
  ~VariableAlreadyExistsError() { };

  virtual char* getMessage() { return NULL; }
  virtual char* getResponse() { return NULL; }
};

class VariableNotDefinedError : public error {
public:
  VariableNotDefinedError() { };
  ~VariableNotDefinedError() { };

  virtual char* getMessage() { return NULL; }
  virtual char* getResponse() { return NULL; }
};

#endif
