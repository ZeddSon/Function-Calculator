#include "Sin.h"

Sin::Sin() : Function("sin(x)") {}


double Sin::calculateFunction(const double& value) {return std::sin(value);}


