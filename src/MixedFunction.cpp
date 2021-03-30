#include "MixedFunction.h"



MixedFunction::MixedFunction(const MixedFunction* other) :Function(other->getFunctionName())
{
    m_func1 = other->m_func1;
    m_func2 = other->m_func2;
    m_operator = other->m_operator;
    m_type = other->m_type; 
}

MixedFunction::MixedFunction(Function* func1, Function* func2,const int i,const int j, const char op):
    m_operator(op),m_type(MIX)
{	


    switch (func1->getType()) {
    case(MIX):
        m_func1 = new MixedFunction((MixedFunction*)func1);
        break;
    case(POLY):
        m_func1 = new Poly((Poly*)func1);
        //m_coefficient = m_func1->getCoeffiecnt();
        break;
    case(NATURALLOG):
        m_func1 = new NaturalLog();
        break;
    case(SIN):
        m_func1 = new Sin();
        break;
    }
    //m_type = m_func1->getType();

    switch (func2->getType()) {
    case(MIX):
        m_func2 = new MixedFunction((MixedFunction*)func2);
        break;
    case(POLY):
        m_func2 = new Poly((Poly*)func2);
        break;
    case(NATURALLOG):
        m_func2 = new NaturalLog();
        break;
    case(SIN):
        m_func2 = new Sin();
        break;
    }

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
        m_func1->setArg("(" + m_func2->printFunctionName() + ")");
        if (m_func1->getType() == POLY) {
            setFunctionName(makeAsPoly());
            break;
        }
        setFunctionName(m_func1->printFunctionName());
        setArg("x");
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

std::string MixedFunction::makeAsPoly() {
    return m_func1->printFunctionName();
}

