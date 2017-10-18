#ifndef VARIABLE_ERROR_H
#define VARIABLE_ERROR_H

#include "error.h"

class NotObjectError : public error {
  public:
    NotObjectError() {}
    ~NotObjectError() {}

    virtual char* getMessage() { return (char *)"Variable is not a valid JSON object."; }
    virtual char* getResponse() { return (char *)"{\"errors\":[{\"status\":\"101\",\"title\":\"Not an object\",\"details\":\"One variable is not a valid JSON object\"}]}"; }
};

class NoNameError : public error {
  public:
    NoNameError() {}
    ~NoNameError() {}

    virtual char* getMessage() { return (char *)"Variable does not contain a name."; }
    virtual char* getResponse() { return (char *)"{\"errors\":[{\"status\":\"102\",\"title\":\"No name\",\"details\":\"No 'name' attribute provided for variable\"}]}"; }
};

class NoSaveError : public error {
  public:
    NoSaveError() {}
    ~NoSaveError() {}

    virtual char* getMessage() { return (char *)"Variable does not contain a save flag."; }
    virtual char* getResponse() { return (char *)"{\"errors\":[{\"status\":\"103\",\"title\":\"No save\",\"details\":\"No 'save' attribute provided for variable\"}]}"; }
};

class NoValuesError : public error {
  public:
    NoValuesError() {}
    ~NoValuesError() {}

    virtual char* getMessage() { return (char *)"Variable has not values."; }
    virtual char* getResponse() { return (char *)"{\"errors\":[{\"status\":\"104\",\"title\":\"No values\",\"details\":\"No 'values' attribute provided for variable\"}]}"; }
};

class NoRankError : public error {
  public:
    NoRankError() {}
    ~NoRankError() {}

    virtual char* getMessage() { return (char *)"Variable has no rank."; }
    virtual char* getResponse() { return (char *)"{\"errors\":[{\"status\":\"105\",\"title\":\"No rank\",\"details\":\"No 'rank' attribute provided for variable\"}]}"; }
};

class NoDimensionsError : public error {
  public:
    NoDimensionsError() {}
    ~NoDimensionsError() {}

    virtual char* getMessage() { return (char *)"Variable has no diemnsiions."; }
    virtual char* getResponse() { return (char *)"{\"errors\":[{\"status\":\"106\",\"title\":\"No dimensions\",\"details\":\"No 'dimensions' attribute provided for variable\"}]}"; }
};

class NameNotStringError : public error {
  public:
    NameNotStringError() {}
    ~NameNotStringError() {}

    virtual char* getMessage() { return (char *)"Variable name is not a string."; }
    virtual char* getResponse() { return (char *)"{\"errors\":[{\"status\":\"107\",\"title\":\"Name no string\",\"details\":\"'name' attribute of a variable does not hold a string\"}]}"; }
};

class SaveNotBoolError : public error {
  public:
    SaveNotBoolError() {}
    ~SaveNotBoolError() {}

    virtual char* getMessage() { return (char *)"Variable save flag is not a boolean value."; }
    virtual char* getResponse() { return (char *)"{\"errors\":[{\"status\":\"108\",\"title\":\"Save not boolean\",\"details\":\"'save' attribute of a variable does not hold a boolean value\"}]}"; }
};

class RankNotInt : public error {
  public:
    RankNotInt() {}
    ~RankNotInt() {}

    virtual char* getMessage() { return (char *)"Variable rank is not an integer."; }
    virtual char* getResponse() { return (char *)"{\"errors\":[{\"status\":\"109\",\"title\":\"Rank not integer\",\"details\":\"'rank' attribute of a variable does not hold a integer value\"}]}"; }
};

class DimensionsNotArray : public error {
  public:
    DimensionsNotArray() {}
    ~DimensionsNotArray() {}

    virtual char* getMessage() { return (char *)"Variable dimesnsions is not an array."; }
    virtual char* getResponse() { return (char *)"{\"errors\":[{\"status\":\"110\",\"title\":\"Dimensions not array\",\"details\":\"'dimesnsions' attribute of a variable does not hold a array of integers\"}]}"; }
};

class ValuesNotArray : public error {
  public:
    ValuesNotArray() {}
    ~ValuesNotArray() {}

    virtual char* getMessage() { return (char *)"Variable values is not an array."; }
    virtual char* getResponse() { return (char *)"{\"errors\":[{\"status\":\"111\",\"title\":\"Values not array\",\"details\":\"'values' attribute of a variable does not hold a array of integers\"}]}"; }
};

class DimensionsWrongSizeError : public error {
  public:
    DimensionsWrongSizeError() {}
    ~DimensionsWrongSizeError() {}

    virtual char* getMessage() { return (char *)"Variable dimesnsions array does not contain the correct number of values."; }
    virtual char* getResponse() { return (char *)"{\"errors\":[{\"status\":\"112\",\"title\":\"Dimensions wrong size\",\"details\":\"'dimesnsions' attribute of a variable does not conatin the correct number of values\"}]}"; }
};

class ValuessWrongSizeError : public error {
  public:
    ValuessWrongSizeError() {}
    ~ValuessWrongSizeError() {}

    virtual char* getMessage() { return (char *)"Variable values array does not contain the correct number of values."; }
    virtual char* getResponse() { return (char *)"{\"errors\":[{\"status\":\"113\",\"title\":\"Values wrong size\",\"details\":\"'values' attribute of a variable does not conatin the correct number of values\"}]}"; }
};

class Rank0Error : public error {
  public:
    Rank0Error() {}
    ~Rank0Error() {}

    virtual char* getMessage() { return (char *)"Variable rank is 0."; }
    virtual char* getResponse() { return (char *)"{\"errors\":[{\"status\":\"114\",\"title\":\"Rank is 0\",\"details\":\"'rank' attribute of a variable is 0 or less\"}]}"; }
};

class OutOfBounds : public error {
  public:
    OutOfBounds() {}
    ~OutOfBounds() {}

    virtual char* getMessage() { return (char *)"Out of bounds error occured."; }
    virtual char* getResponse() { return (char *)"{\"errors\":[{\"status\":\"115\",\"title\":\"Out of bounds\",\"details\":\"An out of bounds error was encounted\"}]}"; }
};

#endif
