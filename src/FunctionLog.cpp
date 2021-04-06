#include "FunctionLog.h"

FunctionLog::FunctionLog(std::shared_ptr<FunctionLog> other) : Function(other->getFunctionName()) ,m_base(other->m_base)
															 , m_function(other->m_function) , m_type(other->m_type){}

FunctionLog::FunctionLog(std::shared_ptr<Function> function, const double& base) : m_function(function) , m_base(base) , m_type(FUNCTIONLOG)
{
	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << base;
	setFunctionName("Log_" + stream.str() + "(" + function->printFunctionName() + ")");
}

double FunctionLog::calculateFunction(const double& value)
{
	return std::log(m_function->calculateFunction(value)) / std::log(m_base);
}
