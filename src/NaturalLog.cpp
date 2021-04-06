#include "NaturalLog.h"

NaturalLog::NaturalLog() : Function("ln"),m_type(NATURALLOG),m_base(std::exp(1)) {}

NaturalLog::NaturalLog(double base, std::shared_ptr<Function> func): Function(("Log_") ,func->printFunctionName() ), m_type(NATURALLOG), m_base(base),m_func(func)
{
	std::ostringstream precision;
	precision << base;
	auto valuePer = precision.str();
	setFunctionName(("Log_") + valuePer);
}


double NaturalLog::calculateFunction(const double& value) { 
	if(m_base == std::exp(1))
		return std::log(value)/std::log(m_base);
	else
		return std::log(m_func->calculateFunction(value)) / std::log(m_base);
}


