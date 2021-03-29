#ifndef SIN_H
#define SIN_H
#include "Function.h"
#include "macros.h"

class Sin : public Function {

private:

public:
    //distructors
    ~Sin() = default;

    //constructors
    Sin();
    //get functions
    char getType() override { return SIN; }
    //set functions

    //calc
    double calculateFunction(const double& value)override;
};
#endif