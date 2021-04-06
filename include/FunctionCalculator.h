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
#include "MixedFunction.h"
#include "Macros.h"

class FunctionCalculator {

private:

    std::vector<std::shared_ptr<Function>> m_function; //vector function

    std::vector<double> m_arguments; // split all the arguments
    std::vector<std::string> m_inputCheck; 
    
    bool m_run = true;
    //enums for the operator
    enum stringOperetion {
        eEval, 
        ePoly,
        eMul,
        eAdd,
        eComp,
        eLog,
        eDel,
        eHelp,
        eExit,
        eError
    };

    bool checkOp();
    void errorMsg(int i); //function with all the errors
    bool checkArguments();
    void printList()const; //print the list of function
    void help() const; //print the help instructor
    void runOperetion(); // start the operator
    FunctionCalculator::stringOperetion getOp(); //gets the operator in enum
    std::string nameArgVal();  //add the argument x value into the function name

public:
    //distructors
    ~FunctionCalculator()=default;

    //constructors
    FunctionCalculator();
    
    void runCalculator(); //main function to run the calculator
    //get functions
    void getAnswer();
    
    
    
};
#endif