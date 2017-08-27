#ifndef ERROR_H
#define ERROR_H

class RanksNotEqualError {
  public:
    RanksNotEqualError() {}
    ~RanksNotEqualError() {}

    virtual char* getMessage() { return "Tensor ranks are not equal."; }
    virtual char* getResponse() { return NULL; }
};

class DimensionsNotEqualError {
  public:
    DimensionsNotEqualError() {}
    ~DimensionsNotEqualError() {}

    virtual char* getMessage() { return "Tensor dimensions are not equal."; }
    virtual char* getResponse() { return NULL; }
};

class NotVectorError {
  public:
    NotVectorError() {}
    ~NotVectorError() {}

    virtual char* getMessage() { return "Operants are not vectors."; }
    virtual char* getResponse() { return NULL; }
};

class NotScalarError {
  public:
    NotScalarError() {}
    ~NotScalarError() {}

    virtual char* getMessage() { return "Operant 1 is not a scalar."; }
    virtual char* getResponse() { return NULL; }
};

#endif
