#include "FunctionCalculator.h"


FunctionCalculator::FunctionCalculator()
{
	//adding the default functions
	m_function.push_back(std::make_shared<Sin>());
	m_function.push_back(std::make_shared<NaturalLog>());

	runCalculator(); 
}


//Main function , runs the calculator
void FunctionCalculator::runCalculator()
{

	while (m_run)
	{
		printList();
		getAnswer();
		if(checkOp()) //checks user input
			runOperetion();

		//clear input, after used
		m_arguments.clear();
		m_inputCheck.clear();
	}
	std::cout << "Goodbye"; //when exit
}

void FunctionCalculator::printList() const
{
	std::cout <<"============================================================"<< std::endl << "Menu: "  << std::endl;

	//prints the list of function with numbers
	for (auto i = 0; i < m_function.size();i++) 
	{
		std::cout << i << ": " << m_function[i]->printFunctionName() << std::endl;
	}

	std::cout << "Please enter a command (\"help\" for command list): ";
}

void FunctionCalculator::getAnswer()
/*
* seprerates thw words from the user's input and checks whether the input
* is valid
*/
{
	//to get answer from standard input
	std::string user_input;

	//create new line and get input
	getline(std::cin , user_input);
	std::cout << std::endl;

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
	std::endl << "del(ete) num - Deletes function #num from function list" << 
	std::endl << "help - Prints this help screen" << 
	std::endl << "exit - Exits the program" << std::endl;
	std::cout << std::endl;

}




bool FunctionCalculator::checkOp()
{
	// for each operator input size should be different , so any case need to be checked.
	if ((m_inputCheck[0].compare("eval") == 0 || m_inputCheck[0].compare("mul") == 0
		|| m_inputCheck[0].compare("add") == 0 || m_inputCheck[0].compare("comp") == 0 ||
		m_inputCheck[0].compare("log") == 0) && m_inputCheck.size() == 3)
	{
		return checkArguments();
	}
	else if (m_inputCheck[0].compare("del") == 0 && m_inputCheck.size() == 2)
	{
		return checkArguments();

	}
	else if (m_inputCheck[0].compare("poly") == 0 && (int)m_inputCheck.size() > 1 && (int)m_inputCheck.size() - 2 == std::stoi(m_inputCheck[1]))
		{
		return checkArguments();
		}

	else if ((m_inputCheck[0].compare("exit") == 0 || m_inputCheck[0].compare("help") == 0) && m_inputCheck.size() == 1) 
	{
		return checkArguments();
	}

	errorMsg(1);
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
				errorMsg(4);
				return false;
			}
		}
			m_arguments.push_back(std::stod(arguments));
			arguments.clear();
	}
	return true;
}
FunctionCalculator::stringOperetion FunctionCalculator::getOp()
/*
* returns the operetion
*/
{
	if (m_inputCheck[0] == "eval") return eEval;
	if (m_inputCheck[0] == "add") return eAdd;
	if (m_inputCheck[0] == "mul") return eMul;
	if (m_inputCheck[0] == "comp") return eComp;
	if (m_inputCheck[0] == "poly") return ePoly;
	if (m_inputCheck[0] == "del") return eDel;
	if (m_inputCheck[0] == "log") return eLog;
	if (m_inputCheck[0] == "help") return eHelp;
	if (m_inputCheck[0] == "exit") return eExit;
	return eError;
}


void FunctionCalculator::runOperetion()
{
	bool wrong_index = 0;
	switch (getOp())
	{
	case(eEval):
		if (m_function.size() > m_arguments[0]) {
			//prints the answer
			std::cout << "Your Answer:" << std::endl << nameArgVal() << " = " << std::fixed << std::setprecision(2) << m_function[m_arguments[0]]->calculateFunction(m_arguments[1]) << std::endl << std::endl;
			return;
		}
		break;
	case(ePoly):
		if (m_arguments[0] == m_arguments.size() - 1)
		{
			//creates a polinumial function
			m_arguments.erase(m_arguments.begin(), m_arguments.begin()+1);
			m_function.push_back(std::make_shared<Poly>(m_arguments));
			return;
		}
		break;
	case(eMul):
		//function multiplication
		if (m_function.size() > m_arguments[0] && m_function.size() > m_arguments[1])
		{
			m_function.push_back(std::make_shared<MixedFunction>(m_function[m_arguments[0]], m_function[m_arguments[1]], m_arguments[0], m_arguments[1], '*'));
			return;
		}
		break;
	case(eAdd):
		//sum of functions
		if (m_function.size() > m_arguments[0] && m_function.size() > m_arguments[1])
		{
			m_function.push_back(std::make_shared<MixedFunction>(m_function[m_arguments[0]], m_function[m_arguments[1]], m_arguments[0], m_arguments[1], '+'));
			return;
		}
		break;
	case(eComp):
		//composite functions
		if (m_function.size() > m_arguments[0] && m_function.size() > m_arguments[1])
		{
			m_function.push_back(std::make_shared<MixedFunction>(m_function[(int)m_arguments[0]], m_function[(int)m_arguments[1]], m_arguments[0], m_arguments[1], 'o'));
			return;
		}
		break;
	case(eLog):
		//creats log of function with choosen base
		if (m_arguments[0] < 0) {
			errorMsg(3);
			return;
		}
		if (m_function.size() > m_arguments[1] &&  m_arguments[1] >= 0)
		{
			m_function.push_back(std::make_shared<NaturalLog>(m_arguments[0],m_function[(int)m_arguments[1]]));
			return;
		}
		break;
		
	case(eDel):
		//delete function
		if (m_function.size() > m_arguments[0] && m_arguments[0] >= 0) {
			m_function.erase(m_function.begin() + m_arguments[0]);
			std::cout << "Function number #" << int(m_arguments[0]) << " has been deleted successfully" << std::endl << std::endl;
			return;
		}
		break;
	case(eHelp):
		//prints help menu
		help();
		return;
	case(eExit):
		//quit the calculator
		m_run = false;
		return;
	}
	errorMsg(2);
}


std::string FunctionCalculator::nameArgVal()
{
	std::ostringstream precision;
	precision << m_arguments[1];
	auto valuePer = precision.str();

	auto title = m_function[m_arguments[0]]->printFunctionName();
	size_t pos = 0;
	
	//replace x with the value
	while ((pos = title.find("x", pos)) != std::string::npos) {
		title.replace(pos, 1, valuePer);
		pos++;
	}
	return title;
}

void FunctionCalculator::errorMsg(int i) {
	switch (i)
	{
	case(1):
		std::cout << "wrong input :( , try again" << std::endl;
		break;
	case(2):
		std::cout << "Wrong index :(" << std::endl;
		break;
	case(3):
		std::cout << "Base must be positive" << std::endl;
		break;
	case(4):
		std::cout << "wrong arguments input :( , try again" << std::endl;
		break;
	}
}