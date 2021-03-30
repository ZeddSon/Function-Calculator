#ifndef NATURALLOG_H
#define NATURALLOG_H
#include "Function.h"
#include "macros.h"

class NaturalLog : public Function {

private:
    char m_type;
public:
    //distructors
    ~NaturalLog() = default;

    //constructors
    NaturalLog();
    //get functions
    char getType() override { return m_type; }
    //set functions

    //calc
   
    double calculateFunction(const double& value)override;
};
#endif