#include "Function.h"

Function::Function(const std::string& name)
{
	m_functionName = name;
}


std::string Function::getFunctionName() const
{
	return this->m_functionName;
}

void Function::setFunctionName(const std::string& set)
{
	this->m_functionName = set;
}

