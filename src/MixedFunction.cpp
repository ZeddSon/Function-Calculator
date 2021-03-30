#include "MixedFunction.h"



MixedFunction::MixedFunction(std::shared_ptr <MixedFunction> other) :Function(other->getFunctionName())
{
    m_func1 = other->m_func1;
    m_func2 = other->m_func2;
    m_operator = other->m_operator;
    m_type = other->m_type; 
}

MixedFunction::MixedFunction(std::shared_ptr<Function> func1, std::shared_ptr<Function> func2,const int i,const int j, const char op):
    m_operator(op),m_type(MIX),m_func1(func1),m_func2(func2)
{	
    
    /*switch (func1->getType()) {
    case(MIX):
        m_func1 = std::make_shared<MixedFunction>((MixedFunction&)func1);
        break;
    case(POLY):
        m_func1 = std::make_shared<Poly>((Poly&)func1);
        //m_coefficient = m_func1->getCoeffiecnt();
        break;
    case(NATURALLOG):
        m_func1 = std::make_shared<NaturalLog>();
        break;
    case(SIN):
        m_func1 = std::make_shared<Sin>();
        break;
    }
    //m_type = m_func1->getType();
    switch (func2->getType()) {
    case(MIX):
        m_func2 = std::make_shared<MixedFunction>((MixedFunction&)func2);
        break;
    case(POLY):
        m_func2 = std::make_shared<Poly>((Poly&)func2);
        break;
    case(NATURALLOG):
        m_func2 = std::make_shared<NaturalLog>();
        break;
    case(SIN):
        m_func2 = std::make_shared<Sin>();
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
        auto title = m_func1->printFunctionName();
        size_t pos = 0;
        while ((pos = title.find("x", pos)) != std::string::npos) {
            title.replace(pos, 1,"(" + m_func2->printFunctionName()+")");
            pos += m_func2->getFunctionName().length()+5;
        }
        setFunctionName(title);
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

