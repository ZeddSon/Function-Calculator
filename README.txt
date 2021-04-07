Function Calculator:


	description:

		 the program is a function calculator. the user can evaluate, create, composite, add, multiply and delete 
		 a function from the list.
		 at any time the user can type help and get instructions.

	files:

		Function.h\cpp: the main variable class. gets a name of function and create the title
	
		Sin.h\cpp: inherent from Function class but can evaluate a sin function of a value

		NaturalLog.h\cpp: inherent from Function class but can evaluate a ln function of a value

		Poly.h\cpp: inherent from Function class created by coficent sent by user and can evaluate the resault of a value

		MixedFunction.h\cpp: inherent from Function class created by 2 functions and can evaluate 
		the sum \ multiplication \ composite the resault of a value.

		FunctionCalculator.h\cpp: the main class. holds a shared ptr vector of functions and handling user operetions and 
		decides if the input is valid.
	

	main structures:

		the main structure for the program is the function shared ptr vector which can hold all the user's functions.

	worth mentioned algorithems: none
	 
	known bugs: none

	notes: none
	
