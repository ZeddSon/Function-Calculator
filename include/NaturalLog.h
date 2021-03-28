#ifndef NATURALLOG_H
#define NATURALLOG_H
#include "Function.h"


class NaturalLog : public Function {

private:

public:
    //distructors
    ~NaturalLog() = default;

    //constructors
    NaturalLog();
    //get functions

    //set functions

    //calc
   
    double calculateFunction(const double& value)override;
};
#endif