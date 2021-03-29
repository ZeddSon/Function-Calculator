#include "MixedFunction.h"



MixedFunction::MixedFunction(const MixedFunction&other)
{
    m_func1 = other.m_func1;
    m_func2 = other.m_func2;
    m_operator = other.m_operator;
}

MixedFunction::MixedFunction(Function* func1, Function* func2,const int i,const int j, const char op):
    m_operator(op),m_func1(func1),m_func2(func2)
{	


    /*switch (func1->getType()) {
    case(MIX):
        m_func1 = new MixedFunction((MixedFunction&)func1);
        break;
    case(POLY):
        m_func1 = new Poly((Poly&)func1);
        break;
    case(NATURALLOG):
        m_func1 = new NaturalLog();
        break;
    case(SIN):
        m_func1 = new Sin();
        break;
    }

    switch (func2->getType()) {
    case(MIX):
        m_func2 = new MixedFunction((MixedFunction&)func2);
        break;
    case(POLY):
        m_func2 = new Poly((Poly&)func2);
        break;
    case(NATURALLOG):
        m_func2 = new NaturalLog();
        break;
    case(SIN):
        m_func2 = new Sin();
        break;
    }*/
    initTitles();
}



void MixedFunction::initTitles()
{
    switch (m_operator)
    {
    case('+'):
        setFunctionName(m_func1->printFunctionName() + " " + m_operator + " " + m_func2->printFunctionName());
        break;
    case('*'):
        setFunctionName("(" + m_func1->printFunctionName() + ")" + " " + m_operator + " " + "(" + m_func2->printFunctionName() + ")");
        break;
    case('o'):
        if (m_func1->getType() == POLY) {
            auto func = Poly((Poly&)m_func1);
            func.setArg("(" + m_func2->printFunctionName() + ")");
        }
        else
            m_func1->setArg("(" + m_func2->printFunctionName() + ")");
        
        setFunctionName(m_func1->printFunctionName());

        break;
    }
}


double MixedFunction::calculateFunction(const double& value)
{
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


