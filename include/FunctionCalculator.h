#ifndef FUNCTIONCALCULATOR_H
#define FUNCTIONCALCULATOR_H
#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include "Function.h"
#include "Sin.h"
#include "NaturalLog.h"
#include "Macros.h"

class FunctionCalculator {

private:

    std::vector<Function*> m_function;
    std::vector<std::string> m_userOperetion;

public:
    //distructors
    ~FunctionCalculator() = default;

    //constructors
    FunctionCalculator();
    void runCalculator();
    //get functions
    void printList()const;
    void getAnswer(std::vector<std::string>& userOperetion);
    void help() const;
    //set functions

};
#endif