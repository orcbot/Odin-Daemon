#ifndef CALCULATIONS_ERROR_H
#define CALCULATIONS_ERROR_H

#include "error.h"

/*
  Custom error objects used to flag errors when preforming calculations
*/

class RanksNotEqualError : public error {
  public:
    RanksNotEqualError() {}
    ~RanksNotEqualError() {}

    virtual char* getMessage() { return (char *)"Tensor ranks are not equal."; }
    virtual char* getResponse() { return (char *)"{\"errors\":[{\"status\":\"201\",\"title\":\"Ranks not equal\",\"details\":\"Unable to preform, ranks of operants are unequal\"}]}"; }
};

class DimensionsNotEqualError : public error {
  public:
    DimensionsNotEqualError() {}
    ~DimensionsNotEqualError() {}

    virtual char* getMessage() { return (char *)"Tensor dimensions are not equal."; }
    virtual char* getResponse() { return (char *)"{\"errors\":[{\"status\":\"202\",\"title\":\"Dimensions not equal\",\"details\":\"Unable to preform, dimensions of operants are unequal\"}]}"; }
};

class NotVectorError : public error {
  public:
    NotVectorError() {}
    ~NotVectorError() {}

    virtual char* getMessage() { return (char *)"Operants are not vectors."; }
    virtual char* getResponse() { return (char *)"{\"errors\":[{\"status\":\"203\",\"title\":\"Not vectors\",\"details\":\"Unable to preform, operants are not vectors\"}]}"; }
};

class NotScalarError : public error {
  public:
    NotScalarError() {}
    ~NotScalarError() {}

    virtual char* getMessage() { return (char *)"Operant 1 is not a scalar."; }
    virtual char* getResponse() { return (char *)"{\"errors\":[{\"status\":\"204\",\"title\":\"Not scalar\",\"details\":\"Unable to preform, neither operant is a scalar\"}]}"; }
};

#endif
