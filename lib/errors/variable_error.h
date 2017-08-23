#ifndef VARIABLE_ERROR_H
#define VARIABLE_ERROR_H

#include "error.h"

class NotObjectError : public error {
  public:
    NotObjectError() {}
    ~NotObjectError() {}

    virtual char* getMessage() { return NULL; }
    virtual char* getResponse() { return NULL; }
};

class NoNameError : public error {
  public:
    NoNameError() {}
    ~NoNameError() {}

    virtual char* getMessage() { return NULL; }
    virtual char* getResponse() { return NULL; }
};

class NoSaveError : public error {
  public:
    NoSaveError() {}
    ~NoSaveError() {}

    virtual char* getMessage() { return NULL; }
    virtual char* getResponse() { return NULL; }
};

class NoValuesError : public error {
  public:
    NoValuesError() {}
    ~NoValuesError() {}

    virtual char* getMessage() { return NULL; }
    virtual char* getResponse() { return NULL; }
};

class NoRankError : public error {
  public:
    NoRankError() {}
    ~NoRankError() {}

    virtual char* getMessage() { return NULL; }
    virtual char* getResponse() { return NULL; }
};

class NoDimensionsError : public error {
  public:
    NoDimensionsError() {}
    ~NoDimensionsError() {}

    virtual char* getMessage() { return NULL; }
    virtual char* getResponse() { return NULL; }
};

class NameNotStringError : public error {
  public:
    NameNotStringError() {}
    ~NameNotStringError() {}

    virtual char* getMessage() { return NULL; }
    virtual char* getResponse() { return NULL; }
};

class SaveNotBoolError : public error {
  public:
    SaveNotBoolError() {}
    ~SaveNotBoolError() {}

    virtual char* getMessage() { return NULL; }
    virtual char* getResponse() { return NULL; }
};

class RankNotInt : public error {
  public:
    RankNotInt() {}
    ~RankNotInt() {}

    virtual char* getMessage() { return NULL; }
    virtual char* getResponse() { return NULL; }
};

class DimensionsNotArray : public error {
  public:
    DimensionsNotArray() {}
    ~DimensionsNotArray() {}

    virtual char* getMessage() { return NULL; }
    virtual char* getResponse() { return NULL; }
};

class ValuesNotArray : public error {
  public:
    ValuesNotArray() {}
    ~ValuesNotArray() {}

    virtual char* getMessage() { return NULL; }
    virtual char* getResponse() { return NULL; }
};

class DimensionsWrongSizeError : public error {
  public:
    DimensionsWrongSizeError() {}
    ~DimensionsWrongSizeError() {}

    virtual char* getMessage() { return NULL; }
    virtual char* getResponse() { return NULL; }
};

class ValuessWrongSizeError : public error {
  public:
    ValuessWrongSizeError() {}
    ~ValuessWrongSizeError() {}

    virtual char* getMessage() { return NULL; }
    virtual char* getResponse() { return NULL; }
};

class Rank0Error : public error {
  public:
    Rank0Error() {}
    ~Rank0Error() {}

    virtual char* getMessage() { return NULL; }
    virtual char* getResponse() { return NULL; }
};

class OutOfBounds : public error {
  public:
    OutOfBounds() {}
    ~OutOfBounds() {}

    virtual char* getMessage() { return NULL; }
    virtual char* getResponse() { return NULL; }
};

#endif
