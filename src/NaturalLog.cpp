#include "NaturalLog.h"

NaturalLog::NaturalLog() : Function("ln") {}


double NaturalLog::calculateFunction(const double& value) { return std::log(value); }


