#ifndef MIXEDFUNCTION_H
#define MIXEDFUNCTION_H

#include "Function.h"
#include "macros.h"
#include "Poly.h"
#include "Sin.h"
#include "NaturalLog.h"

class MixedFunction : public Function
{
	
private:
	std::vector<double> m_coefficient;
	std::shared_ptr<Function> m_func1,m_func2;
	char m_operator;
	char m_type;

	void initTitles(); //creates the title of the composite function

public:
	//constructors
	MixedFunction(std::shared_ptr<Function>, std::shared_ptr<Function>, const int, const int,const char);

	//calculate function
	virtual double calculateFunction(const double& value);

	//get function
	char getType() override { return m_type; }

};

#endif