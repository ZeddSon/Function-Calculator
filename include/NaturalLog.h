#ifndef NATURALLOG_H
#define NATURALLOG_H
#include "Function.h"
#include "macros.h"

class NaturalLog : public Function {

private:
    char m_type;
    double m_base;
    std::shared_ptr<Function> m_func;
public:
    //distructors
    ~NaturalLog() = default;

    //constructors
    NaturalLog();
    NaturalLog(double, std::shared_ptr<Function>);
    //get functions
    char getType() override { return m_type; }
    //set functions

    //calc
   
    double calculateFunction(const double& value)override;
};
#endif