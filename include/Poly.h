#ifndef POLY_H
#define POLY_H
#include "Function.h"


class Poly : public Function {

private:

    vector<float> m_coefficient;

public:

    //distructors
    ~Poly() = default;

    //constructors
    Poly();
    Poly(std::vector<float>);
    //get functions

    //set functions

    //calc
    double calculateFunction(const double& value)override;
};
#endif