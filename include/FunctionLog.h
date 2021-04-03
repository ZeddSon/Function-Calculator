#ifndef FUNCTIONLOG_H
#define FUNCTIONLOG_H

#include "Function.h"
#include "macros.h"
#include "Poly.h"
#include "Sin.h"
#include "NaturalLog.h"
#include "MixedFunction.h"

class FunctionLog : public Function
{
	
private:

	double m_base;
	std::shared_ptr<Function> m_function;
	char m_type;


public:

	FunctionLog(std::shared_ptr <FunctionLog> other);
	FunctionLog(std::shared_ptr<Function>,  const double&);
	virtual double calculateFunction(const double& value);
	char getType() override { return m_type; }

};

#endif