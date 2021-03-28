#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <limits>

class Sin;

class Function 
{
private:
    
    std::string m_functionName;

public:

    //distructors
    ~Function() = default;

    //constructors
    Function() {};
    Function(const std::string& name);

    //get functions
    std::string getFunctionName() const;

    //set functions
    void setFunctionName(const std::string& set);

    virtual double calculateFunction(const double& value) = 0;

};
#endif 

