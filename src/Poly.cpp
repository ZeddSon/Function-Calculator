#include "Poly.h"


Poly::Poly() :Function("0"), m_type(POLY) {}

Poly::Poly(const std::vector<double>& coefficient) : m_coefficient(coefficient), Function("0"), m_type(POLY) {}


double Poly::calculateFunction(const double& value)
{
	double answer = 0;
	for (int i = 0; i < m_coefficient.size(); i++) {
		answer += m_coefficient[i] * pow(value, i);
	}
	return answer;
}

std::string Poly::printFunctionName()
{
	int precision = 2;
	std::stringstream stream;
	std::string title;
	for (int i = m_coefficient.size() - 1; i >= 0; i--) {
		if (m_coefficient[i] != 0) {
			if (!title.empty())
				title += " + ";
			stream << std::fixed << std::setprecision(checkDigits(m_coefficient[i])) << m_coefficient[i];
			title += stream.str();
			if (i > 0) {
				title += getArg();
				title += "^";
				title += std::to_string(i);	
			}
			stream.str("");
		}
	}
	if (title.empty())
		return "0";
	return title;
}





int Poly::checkDigits(double num)
{
	if (int(num * 10) % 10 == 0) {
		if (int(num * 100) % 10 == 0)
			return 0;
		return 2;
	}
	else if (int(num * 100) % 10 != 0)
		return 2;


	return 1;
}


