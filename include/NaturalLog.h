#ifndef NATURALLOG_H
#define NATURALLOG_H
#include "Function.h"
#include "macros.h"

class NaturalLog : public Function {

private:

public:
    //distructors
    ~NaturalLog() = default;

    //constructors
    NaturalLog();
    //get functions
    char getType() override { return NATURALLOG; }
    //set functions

    //calc
   
    double calculateFunction(const double& value)override;
};
#endif