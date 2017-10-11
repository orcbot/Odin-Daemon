#ifndef ERROR_H
#define ERROR_H

/*
  Custom error objects used to flag errors when preforming calculations
*/

class RanksNotEqualError {
  public:
    RanksNotEqualError() {}
    ~RanksNotEqualError() {}

    virtual char* getMessage() { return "Tensor ranks are not equal."; }
    virtual char* getResponse() { return "{\"errors\":[{\"status\":\"201\",\"title\":\"Ranks not equal\",\"details\":\"Unable to preform, ranks of operants are unequal\"}]}"; }
};

class DimensionsNotEqualError {
  public:
    DimensionsNotEqualError() {}
    ~DimensionsNotEqualError() {}

    virtual char* getMessage() { return "Tensor dimensions are not equal."; }
    virtual char* getResponse() { return "{\"errors\":[{\"status\":\"202\",\"title\":\"Dimensions not equal\",\"details\":\"Unable to preform, dimensions of operants are unequal\"}]}"; }
};

class NotVectorError {
  public:
    NotVectorError() {}
    ~NotVectorError() {}

    virtual char* getMessage() { return "Operants are not vectors."; }
    virtual char* getResponse() { return "{\"errors\":[{\"status\":\"203\",\"title\":\"Not vectors\",\"details\":\"Unable to preform, operants are not vectors\"}]}"; }
};

class NotScalarError {
  public:
    NotScalarError() {}
    ~NotScalarError() {}

    virtual char* getMessage() { return "Operant 1 is not a scalar."; }
    virtual char* getResponse() { return "{\"errors\":[{\"status\":\"204\",\"title\":\"Not scalar\",\"details\":\"Unable to preform, neither operant is a scalar\"}]}"; }
};

#endif
