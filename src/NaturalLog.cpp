#include "NaturalLog.h"

NaturalLog::NaturalLog() : Function("ln"),m_type(NATURALLOG) {}


double NaturalLog::calculateFunction(const double& value) { return std::log(value); }


