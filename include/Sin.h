#ifndef SIN_H
#define SIN_H
#include "Function.h"


class Sin : public Function {

private:

public:
    //distructors
    ~Sin() = default;

    //constructors
    Sin();
    //get functions

    //set functions

    //calc
    double calculateFunction(const double& value)override;
};
#endif