#include "MixedFunction.h"


MixedFunction::MixedFunction(std::shared_ptr<Function> func1, std::shared_ptr<Function> func2,const int i,const int j, const char op):
    m_operator(op),m_type(MIX),m_func1(func1),m_func2(func2)
{	
    initTitles();
}

void MixedFunction::initTitles()
{
    switch (m_operator)
    {
    case('+'):
        //for Add fucntions
        setFunctionName(m_func1->printFunctionName() + " " + m_operator + " " + m_func2->printFunctionName());
        break;

    case('*'):
        //for Mul fucntions
        setFunctionName("(" + m_func1->printFunctionName() + ")" + " " + m_operator + " " + "(" + m_func2->printFunctionName() + ")");
        break;

    case('o'):
        //for comp fucntions
        auto title = m_func1->printFunctionName();
        size_t pos = 0;

        //replace x with the second function name
        while ((pos = title.find("x", pos)) != std::string::npos) 
        {
            title.replace(pos, 1,"(" + m_func2->printFunctionName()+")");
            pos += m_func2->printFunctionName().length()+5;
        }
        setFunctionName(title);
        break;
    }
}


double MixedFunction::calculateFunction(const double& value)
{
    //calculate the 2 functions and use the choosen operator
    switch (m_operator) 
    {
    case('+'):
        return m_func1->calculateFunction(value) + m_func2->calculateFunction(value);

    case('*'):

        return m_func1->calculateFunction(value) * m_func2->calculateFunction(value);

    case('o'):

        return m_func1->calculateFunction(m_func2->calculateFunction(value));

    }
    return 0;
}


