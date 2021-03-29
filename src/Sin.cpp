#include "Sin.h"

Sin::Sin() : Function("sin") {}


double Sin::calculateFunction(const double& value) 
{
	double pi = 3.14159;
	return std::sin((value * pi) / 180);
}


