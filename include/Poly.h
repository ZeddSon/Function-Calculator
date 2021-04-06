#ifndef POLY_H
#define POLY_H
#include "Function.h"
#include "macros.h"



class Poly : public Function {

private:

    std::vector<double> m_coefficient;
    char m_type;
    int checkDigits(double); //digit counting
public:

    //distructors
    ~Poly() = default;

    //constructors
    Poly();

    Poly(const std::vector<double>&);
    //get functions
    char getType() override { return m_type; }
    //set functions

    //calc
    double calculateFunction(const double& value)override;
    std::string printFunctionName() override; //creats title name and returns it

};
#endif