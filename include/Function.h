#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <limits>

class Sin;

class Function 
{
private:
    
    std::string m_functionName, m_arg, m_name;

public:

    //distructors
    ~Function() = default;

    //constructors
    Function() {};
    Function(const std::string& name, const std::string& = "x");

    //get functions
    virtual std::string printFunctionName();
    virtual std::string getFunctionName();
    virtual char getType()=0;

    //set functions
    void setFunctionName(const std::string& set);

    std::string getArg() const;

    //set functions
    void setArg(const std::string& set);

    virtual double calculateFunction(const double& value) = 0;

};
#endif 

