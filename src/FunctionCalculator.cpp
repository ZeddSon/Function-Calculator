#include "FunctionCalculator.h"

FunctionCalculator::FunctionCalculator()
{
	//allocate the default functions
	m_function.push_back(new Sin());
	m_function.push_back(new NaturalLog());

	runCalculator();
}

void FunctionCalculator::runCalculator()
{
	auto run = true;

	while (run)
	{
		printList();
		getAnswer(m_userOperetion);
		if (m_userOperetion.size() > 0) {
			if (m_userOperetion[0].compare("help") == 0) {
				help();
			}
			if (m_userOperetion[0].compare("eval") == 0) {

				std::cout << m_function[stoi(m_userOperetion[1])]->calculateFunction(stod(m_userOperetion[2])) << std::endl;
			}
		}
	}

}

void FunctionCalculator::printList() const
{
	//prints the list of function with numbers

	for (auto i = 0; i < m_function.size();i++) 
	{
		std::cout << i << ": " << m_function[i]->getFunctionName() << std::endl;
	}

	std::cout << "Please enter a command (\"help for\" command list): ";
}

void FunctionCalculator::getAnswer(std::vector<std::string>& userOperetion)
{
	/*
	*seprerates thw words from the user's input and checks whether the input
	* is valid
	*/

	//clears vector if used before
	userOperetion.clear();

	//to get answer from standard input
	std::string str;

	//create new line and get input
	userOperetion.push_back("");
	getline(std::cin , str);
	int vecIndex = 0;
	bool dotCounter = false;

	//seperate line into words and numbes
	for (int i = 0; i < str.size();i++) 
	{
		//add new string to vector
		if (str[i] == ' ') 
		{
			userOperetion.push_back({});
			vecIndex++;
			dotCounter = false;
			continue;
		}

		//check if the arguments are numbers
		if (m_userOperetion.size() > 1) {

			if (str[i] >= '0' && str[i] <= '9' || str[i] == '.' && !dotCounter) 
			{
				if (str[i] == '.') dotCounter = true;
				userOperetion[vecIndex].push_back(str[i]);
			}
			else
			{
				std::cout << "wrong input :( , try again" << std::endl;
				userOperetion.clear();
				return;
			}
		}
		else userOperetion[vecIndex].push_back(str[i]);
	}


	


}	

void FunctionCalculator::help() const
{
	//prints the help text

	std::cout << "Following is the list of the calculator's available commands: " <<
	std::endl << "eval(uate) num x - Evaluates function #num on x" <<
	std::endl << "poly(nomial) N c0 c1 ... cN - 1 - Creates a polynomial with N coefficients" <<
	std::endl << "mul(tiply) num1 num2 - Creates a function that is the multiplication of" <<
	std::endl << "function #num1 and function #num2" <<
	std::endl << "add num1 num2 - Creates a function that is the sum of function #num1 and" <<
	std::endl << "function #num2" <<
	std::endl << "comp(osite) num1 num2 - Creates a function that is the composition of" <<
	std::endl << "function #num1 and function #num2" <<
	std::endl << "log N num - Creates a function that computes log N of function #num" <<
	std::endl << "del(ete) num - Deletes function #num from function list" << std::endl;
}
