#ifndef FUNCTIONCALCULATOR_H
#define FUNCTIONCALCULATOR_H
#include <memory>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Function.h"
#include "Sin.h"
#include "Poly.h"
#include "NaturalLog.h"
#include "FunctionLog.h"
#include "MixedFunction.h"
#include "Macros.h"

class FunctionCalculator {

private:

    std::vector<Function*> m_function;
    std::vector<std::shared_ptr<Function>> m_func1;
    std::string m_userOperetion;
    std::vector<double> m_arguments;
    std::vector<std::string> m_inputCheck;
    bool m_run = true;

    enum stringOperetion {
        eEval,
        ePoly,
        eMul,
        eAdd,
        eComp,
        eDel,
        eHelp,
        eLog,
        eExit,
        eError
    };

    bool checkOp();
    bool checkArguments();
    FunctionCalculator::stringOperetion getOp();
public:
    //distructors
    ~FunctionCalculator();

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