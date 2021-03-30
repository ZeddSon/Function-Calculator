#ifndef SIN_H
#define SIN_H
#include "Function.h"
#include "macros.h"

class Sin : public Function {

private:
    char m_type;
public:
    //distructors
    ~Sin() = default;

    //constructors
    Sin();
    //get functions
    char getType() override { return m_type; }
    //set functions

    //calc
    double calculateFunction(const double& value)override;
};
#endif