#ifndef ERROR_H
#define ERROR_H

class error {
  public:
    error() {}
    ~error() {}

    virtual char* getMessage() = 0;
    virtual char* getResponse() = 0;

};

#endif
