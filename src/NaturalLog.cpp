#include "NaturalLog.h"

NaturalLog::NaturalLog() : Function("ln(x)") {}


double NaturalLog::calculateFunction(const double& value) { return std::log(value); }


