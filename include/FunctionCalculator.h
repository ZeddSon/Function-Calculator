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
    std::string m_userOperetion;
    std::vector<double> m_arguments;
    std::vector<std::string> m_inputCheck;
    
    enum stringOperetion {
        eEval,
        ePoly,
        eMul,
        eAdd,
        eComp,
        eDel,
        eHelp,
        eExit
    };

    bool checkOp();
    bool checkArguments();
    int getOp();
public:
    //distructors
    ~FunctionCalculator() = default;

    //constructors
    FunctionCalculator();
    void runCalculator();
    //get functions
    void printList()const;
    void getAnswer();
    void help() const;
    void runOperetion();
    
};
#endif