#ifndef VARLIST_ERROR_H
#define VARLIST_ERROR_H

#include "error.h"

class VariableNotFoundError : public error {
public:
  VariableNotFoundError() { };
  ~VariableNotFoundError() { };

  virtual char* getMessage() { return "Variable requested was not found."; }
  virtual char* getResponse() { return "{\"errors\":[{\"status\":\"301\",\"title\":\"Variable not found\",\"details\":\"A variable was not found.\"}]}";; }
};

class VariableAlreadyExistsError : public error {
public:
  VariableAlreadyExistsError() { };
  ~VariableAlreadyExistsError() { };

  virtual char* getMessage() { return "Variable already exists."; }
  virtual char* getResponse() { return "{\"errors\":[{\"status\":\"302\",\"title\":\"Variable already exists\",\"details\":\"Name is already used by another vairable.\"}]}"; }
};

class VariableNotDefinedError : public error {
public:
  VariableNotDefinedError() { };
  ~VariableNotDefinedError() { };

  virtual char* getMessage() { return "Variable was not defined."; }
  virtual char* getResponse() { return "{\"errors\":[{\"status\":\"304\",\"title\":\"Variable was not defined\",\"details\":\"Variable was not defined and cannot be used.\"}]}"; }
};

#endif
