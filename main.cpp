#include "InvestmentCalculator.h" // Include the InvestmentCalculator header file to use the class and its methods
#include <exception> // Include the exception header file to handle exceptions
#include <iostream> // Include the iostream header file to use input and output streams

using namespace std;

int main() {
	// Create an instance of the InvestmentCalculator class and run the calculator
	try {
		InvestmentCalculator calculator;

		calculator.runCalculator();
	}

	// Catch any exceptions thrown during the execution of the Investment Calculator program
	catch (const std::exception& t_exception) {
		cerr << "Error: " << t_exception.what() << endl;
		return 1;
	}

	return 0;
};
