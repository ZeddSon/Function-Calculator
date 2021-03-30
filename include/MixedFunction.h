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
	Function *m_func1,*m_func2;
	char m_operator;

	void initTitles();

	std::string makeAsPoly();
	char m_type;



public:
	MixedFunction(const MixedFunction*);
	MixedFunction(Function*, Function*, const int, const int,const char);
	virtual double calculateFunction(const double& value);
	char getType() override { return m_type; }

};





#endif