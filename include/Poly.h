#ifndef POLY_H
#define POLY_H
#include "Function.h"
#include "macros.h"



class Poly : public Function {

private:

    std::vector<double> m_coefficient;
    char m_type;
    int checkDigits(double);
public:

    //distructors
    ~Poly() = default;

    //constructors
    Poly();
    Poly(const std::shared_ptr<Poly>);
    Poly(const std::vector<double>&);
    //get functions
    char getType() override { return m_type; }
    std::vector<double> getCoeffiecnt() override;
    //set functions

    //calc
    double calculateFunction(const double& value)override;
    std::string printFunctionName() override;
    //std::string getFunctionName() ;
};
#endif