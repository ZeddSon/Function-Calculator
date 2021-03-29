#ifndef POLY_H
#define POLY_H
#include "Function.h"


class Poly : public Function {

private:

    std::vector<double> m_coefficient;
    int checkDigits(double);


public:

    //distructors
    ~Poly() = default;

    //constructors
    Poly();
    Poly(const std::vector<double>&);
    //get functions

    //set functions

    //calc
    double calculateFunction(const double& value)override;
};
#endif