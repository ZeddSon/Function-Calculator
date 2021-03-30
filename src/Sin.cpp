#include "Sin.h"

Sin::Sin() : Function("sin"),m_type(SIN) {}


double Sin::calculateFunction(const double& value)
{
	double pi = 3.14159;
	return std::sin(value);
}


