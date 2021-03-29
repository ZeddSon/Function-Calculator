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
		getAnswer();
		runOperetion();

		m_userOperetion.clear();
		m_arguments.clear();
	}

}

void FunctionCalculator::printList() const
{
	//prints the list of function with numbers

	for (auto i = 0; i < m_function.size();i++) 
	{
		std::cout << i << ": " << m_function[i]->getFunctionName() << std::endl;
	}

	std::cout << "Please enter a command (\"help\" for command list): ";
}

void FunctionCalculator::getAnswer()
/*
* seprerates thw words from the user's input and checks whether the input
* is valid
*/
{
	//clears vector if used before
	m_userOperetion.clear();

	//to get answer from standard input
	std::string user_input;

	//create new line and get input
	getline(std::cin , user_input);

	size_t pos = 0;

	//seperate to words
	while ((pos = user_input.find(" ")) != std::string::npos)
	{
		if (user_input.substr(0, pos) != "")
			m_inputCheck.push_back(user_input.substr(0, pos));
		user_input.erase(0, pos + 1);
	}
	m_inputCheck.push_back(user_input.substr(0, pos));

	//clear string
	user_input.clear();


	checkOp();
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




bool FunctionCalculator::checkOp()
{
	if ((m_inputCheck[0].compare("eval") == 0 || m_inputCheck[0].compare("mul") == 0
		|| m_inputCheck[0].compare("add") == 0 || m_inputCheck[0].compare("comp") == 0 ||
		m_inputCheck[0].compare("log") == 0) && m_inputCheck.size() == 3)
	{
		return checkArguments();
	}
	else if (m_userOperetion.compare("del") == 0 && m_inputCheck.size() == 2)
	{
		return checkArguments();
		
	}
	else if (m_userOperetion.compare("poly") == 0 && m_inputCheck.size() - 2 == std::stoi(m_inputCheck[1]))
	{
		return checkArguments();
	}
	std::cout << "wrong input :( , try again" << std::endl;
	return false;
}

bool FunctionCalculator::checkArguments()
{
	//for each argument string
	std::string arguments = "";

	//check if the argument is valid
	for (int i = 1; i < m_inputCheck.size(); i++) {
		//to count dots
		int dotCounter = 0;
		//check each charecter
		for (int j = 0; j < m_inputCheck[i].size(); j++)
		{
			if ((m_inputCheck[i][j] >= '0' && m_inputCheck[i][j] <= '9') || (m_inputCheck[i][j] == '.' && dotCounter < 1))
			{
				arguments.push_back(m_inputCheck[i][j]);
				if (m_inputCheck[i][j] == '.') dotCounter++;
			}

			else if ((m_inputCheck[i][j] == '-' || m_inputCheck[i][j] == '+') && j == 0)
			{
				arguments.push_back(m_inputCheck[i][j]);
			}

			else
			{
				std::cout << "wrong input :( , try again" << std::endl;
				return false;
			}
		}

		m_arguments.push_back(std::stod(arguments));
		arguments.clear();
	}

	m_userOperetion = m_inputCheck[0];
	m_inputCheck.clear();
	return true;
}
int FunctionCalculator::getOp()
/*
* returns the operetion
*/
{
	if (m_userOperetion == "eval") return eEval;
	if (m_userOperetion == "add") return eAdd;
	if (m_userOperetion == "mul") return eMul;
	if (m_userOperetion == "comp") return eComp;
	if (m_userOperetion == "poly") return ePoly;
	if (m_userOperetion == "help") return eHelp;
	if (m_userOperetion == "exit") return eExit;
	std::cout << m_function[m_arguments[0]]->calculateFunction(m_arguments[1]) << std::endl;
	return -1;
}
void FunctionCalculator::runOperetion()
{
	switch (getOp())
	{
	case(eEval):
		if (m_function.size() > m_arguments[0])
			std::cout << m_function[m_arguments[0]]->calculateFunction(m_arguments[1]) << std::endl;
		break;
	}
}