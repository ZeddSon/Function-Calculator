#include "Function.h"

Function::Function(const std::string& name, const std::string&arg):m_arg(arg),m_name(name)
{
	m_functionName = name;
	
}



std::string Function::printFunctionName()
{
	if (m_arg.compare("") == 0) {
		return getFunctionName();
	}
	return this->m_functionName + "(" + m_arg + ")";
}
std::vector<double> Function::getCoeffiecnt()
{
	return std::vector<double>();
}
std::string Function::getFunctionName() const
{
	return this->m_functionName;
}


void Function::setFunctionName(const std::string& set)
{
	this->m_functionName = set;
}

std::string Function::getArg() const
{
	return m_arg;
}

void Function::setArg(const std::string& set)
{
	m_arg = set;
}

