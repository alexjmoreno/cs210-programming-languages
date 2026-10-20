#include "InvestmentCalculator.h" // Include the InvestmentCalculator header file to use the class and its methods
#include <iostream> // Include the iostream header file to use input and output streams
#include <iomanip> // Include the iomanip header file to use manipulators for formatting output
#include <limits> // Include the limits header file to use numeric limits for input validation
#include <string> // Include the string header file to use the string class
#include <sstream> // Include the sstream header file to use string streams for input validation
#include <stdexcept> // Include the stdexcept header file to use standard exceptions for error handling

using namespace std;


// Retrieve InvestmentCalculator member values
double InvestmentCalculator::getInitialInvestment() {
    return m_initialInvestmentAmount;
}

double InvestmentCalculator::getMonthlyDeposit() {
    return m_monthlyDeposit;
}

double InvestmentCalculator::getAnnualInterest() {
    return m_annualInterestPercentage;
}

int InvestmentCalculator::getNumYears() {
    return m_numYears;
}

int InvestmentCalculator::getNumMonths() {
    return convertYearToMonths(m_numYears);
}

// Validate input values of type double, return true if valid, if successful, return true and assign the value to the reference variable
bool InvestmentCalculator::validDoubleInput(double& t_inputDouble, double t_minimum) {
    string input;

    while (true) {
        if (!getline(cin, input)) {
			throw runtime_error("Unable to read input."); // Throw an exception if input cannot be read
        }

        istringstream inputStream(input);
        double value;
        char extraCharacter;

		if ((inputStream >> value) && // Valid double input and no extra characters
            value >= t_minimum &&
            !(inputStream >> extraCharacter)) {
            t_inputDouble = value;
            return true;
        }

		cout << "Invalid input! Please enter an amount of at least " << t_minimum << ": "; // Prompt user for valid input
    }
}

// Validate input values of type int, return true if valid and assign the value to the reference variable
bool InvestmentCalculator::validIntInput(int& t_inputInt) {
    string input;

    while (true) {
        if (!getline(cin, input)) {
			throw runtime_error("Unable to read input."); // Throw an exception if input cannot be read
        }

        istringstream inputStream(input);
        int value;
        char extraCharacter;

		if ((inputStream >> value) && // Valid integer input and no extra characters
            value >= 1 &&
            value <= 100 &&
            !(inputStream >> extraCharacter)) {
            t_inputInt = value;
            return true;
        }

		cout << "Invalid input! Please enter a whole number from 1 to 100: "; // Prompt user for valid input
    }
}

// Validate menu input and return true if valid 
// This validation is specifically for the menu options, which are whole numbers from 0 to 7
bool InvestmentCalculator::validMenuInput(int& t_userInput) {
    string input;

    while (true) {
        if (!getline(cin, input)) {
			throw runtime_error("Unable to read input."); // Throw an exception if input cannot be read
        }

        istringstream inputStream(input);
        int value;
        char extraCharacter;

		if ((inputStream >> value) && // Valid integer input and no extra characters
            value >= 0 &&
            value <= 7 &&
            !(inputStream >> extraCharacter)) {
            t_userInput = value;
            return true;
        }

		cout << "Invalid option! Please enter a whole number from 0 to 7: "; // Prompt user for valid input
    }
}

// Set InvestmentCalculator private member values
void InvestmentCalculator::setInitialInvestment(double t_initialInvestment) {
	if (validDoubleInput(t_initialInvestment)) { // Validate input before setting the value
        m_initialInvestmentAmount = t_initialInvestment;
    }
}

void InvestmentCalculator::setMonthlyDeposit(double t_monthlyDeposit) {
	if (validDoubleInput(t_monthlyDeposit, 0.00)) { // Validate input before setting the value, allowing 0.00 as a valid input
        m_monthlyDeposit = t_monthlyDeposit;
    }
}

void InvestmentCalculator::setAnnualInterest(double t_annualInterest) {
    if (validDoubleInput(t_annualInterest, 0.00)) {
        m_annualInterestPercentage = t_annualInterest;
    }
}

void InvestmentCalculator::setNumYears(int t_numberYears) {
    if (validIntInput(t_numberYears)) {
        m_numYears = t_numberYears;
    }
}

// Format money values to 2 decimal places and add a dollar sign before the value, returning a string
string InvestmentCalculator::formatMoney(double t_amount) const {
    ostringstream output;
    output << "$" << fixed << setprecision(2) << t_amount;
    return output.str();
}

// Print a border of asterisks for the user menu
void InvestmentCalculator::printUserMenuTopBorder() {
    unsigned int width = 40;
    unsigned int i;

    for (i = 0; i < width; ++i) {
        cout << "*";

        if (i == width - 1) {
            cout << endl;
        }
    }
}

// Calculations based on values
// Converts years to months
int InvestmentCalculator::convertYearToMonths(int t_numYears) {
    int yearsAsMonths;

    yearsAsMonths = (t_numYears * 12);

    return yearsAsMonths;
}

// Calculate the year-end balance based on initial investment, annual interest, number of years, and monthly deposit
double InvestmentCalculator::calcYearEndBalance(
    double t_initialInvestment,
    double t_annualInterest,
    int t_numberYears,
    double t_monthlyDeposit)
    {
    
    double balance = t_initialInvestment;
    double monthlyInterestRate = (t_annualInterest / 100.0) / 12.0;
    int totalMonths = (t_numberYears * 12);

    for (int month = 0; month < totalMonths; ++month) {
        balance += t_monthlyDeposit;
        balance += balance * monthlyInterestRate;
    }

    return balance;
}

// Print the user menu with the current values of the InvestmentCalculator private members
void InvestmentCalculator::printMenu() {
    string title = " Scenario Values ";
    size_t width = 40;
    size_t starCount = width - title.length() - 2;
    size_t sideStars = starCount / 2;
    size_t i;

    cout << endl;
    cout << endl;
	printUserMenuTopBorder(); // Print the top border of the user menu

	for (i = 0; i < sideStars; ++i) { // Print the left side asterisks and a space before the title
        cout << "*";

        if (i == sideStars - 1) {
            cout << " ";
        }
    }

    cout << title << " ";

	for (i = 0; i <= sideStars; ++i) { // Print the right side asterisks and a space after the title
        cout << "*";

        if (i == sideStars) {
            cout << " ";
        }
    }

    cout << endl;

	printUserMenuTopBorder();

	// Print the current values of the InvestmentCalculator private members
    cout << "Initial Investment Amount: " << getInitialInvestment() << endl;
    cout << "Monthly Deposit: " << getMonthlyDeposit() << endl;
    cout << "Annual Interest: " << getAnnualInterest() << endl;
    cout << "Number of years: " << getNumYears() << endl;

    printUserMenuTopBorder();
    cout << endl;
    cout << endl;
}

// Print the report header with the title centered and column headers for year, year-end balance, and year-end earned interest
void InvestmentCalculator::printReportHeader(
    const string& t_title,
    ostream& t_output
    ) {
	const int TABLE_WIDTH = 60; // Set the widths for the table and columns
    const int YEAR_WIDTH = 8;
    const int BALANCE_WIDTH = 26;
    const int INTEREST_WIDTH = 26;

    size_t leftPadding = 0;

	if (t_title.length() < TABLE_WIDTH) { // Calculate the left padding to center the title
        leftPadding = (TABLE_WIDTH - t_title.length()) / 2;
    }

	t_output << string(TABLE_WIDTH, '-') << endl; // Print the top border of the report

	t_output << string(leftPadding, ' ') << t_title << endl; // Print the title centered with left padding

	t_output << string(TABLE_WIDTH, '=') << endl; // Print the separator line between the title and column headers

	// Print the column headers for year, year-end balance, and year-end earned interest
    t_output << left << setw(YEAR_WIDTH) << "Year"
        << right << setw(BALANCE_WIDTH) << "Year-End Balance"
        << setw(INTEREST_WIDTH) << "Year-End Earned Interest"
        << endl;

	t_output << string(TABLE_WIDTH, '-') << endl; // Print the separator line between the column headers and the data
}

// Show Balance and Interest Report without monthly deposits
void InvestmentCalculator::balanceReportNoDeposits( 
    double t_initialInvestment,
	double t_annualInterest,
	int t_numYears,
	ostream& t_output
    ) {
    string title = "Balance and Interest Report Without Monthly Deposits";

	const int YEAR_WIDTH = 8; // Set the widths for the table and columns
    const int BALANCE_WIDTH = 26;
    const int INTEREST_WIDTH = 26;

    t_output << endl;
    printReportHeader(title, t_output);

	for (int year = 1; year <= t_numYears; ++year) { // Loop through each year and calculate the year-end balance and earned interest
        
        double earnedInterest = 0.0;
        
		for (int month = 1; month <= 12; ++month) { // Nested loop to calculate the monthly interest and update the year-end balance and earned interest
			
            double monthlyInterest = t_initialInvestment * (t_annualInterest / 100.0) / 12.0;
            
            t_initialInvestment += monthlyInterest;

            earnedInterest += monthlyInterest;
		}

		// Print the year, year-end balance, and year-end earned interest for each year
        t_output << left << setw(YEAR_WIDTH) 
            << year << right 
            << setw(BALANCE_WIDTH) << formatMoney(t_initialInvestment)
            << setw(INTEREST_WIDTH) << formatMoney(earnedInterest)
            << endl;
    }

}

// Show Balance and Interest Report with monthly deposits
void InvestmentCalculator::balanceReportWithDeposits( 
    double t_initialInvestment,
    double t_annualInterest,
    int t_numYears,
	double t_monthlyDeposit,
	ostream& t_output
) {
    string title = "Balance and Interest Report With Monthly Deposits";

	const int YEAR_WIDTH = 8; // Set the widths for the table and columns
    const int BALANCE_WIDTH = 26;
    const int INTEREST_WIDTH = 26;
	const double MONTHLY_INTEREST_RATE = (t_annualInterest / 100.0) / 12.0; // Calculate the monthly interest rate based on the annual interest rate

    double balance = t_initialInvestment;
    

    t_output << endl;
    printReportHeader(title, t_output);

	for (int year = 1; year <= t_numYears; ++year) { // Loop through each year and calculate the year-end balance and earned interest with monthly deposits
        double earnedInterest = 0.0;

		for (int month = 1; month <= 12; ++month) { // Nested loop to calculate the monthly interest and update the year-end balance and earned interest with monthly deposits
            balance += t_monthlyDeposit;

            double monthlyInterest = balance * MONTHLY_INTEREST_RATE;
            balance += monthlyInterest;
            earnedInterest += monthlyInterest;
        }

		// Print the year, year-end balance, and year-end earned interest for each year with monthly deposits
        t_output << left << setw(YEAR_WIDTH)
            << year << right
            << setw(BALANCE_WIDTH) << formatMoney(balance)
            << setw(INTEREST_WIDTH) << formatMoney(earnedInterest)
            << endl;
    }

}

// Print both reports side-by-side for comparison
void InvestmentCalculator::printReports() {
	const int TABLE_WIDTH = 60; // Set the widths for EACH table

	ostringstream noDepositsOutput; // Create two ostringstream objects to capture the output of the reports
    ostringstream withDepositsOutput;

    // Call the balanceReportNoDeposits function to generate the report and store the output in the noDepositsOutput
	balanceReportNoDeposits( 
        getInitialInvestment(),
        getAnnualInterest(),
        getNumYears(),
        noDepositsOutput
    );

	// Call the balanceReportWithDeposits function to generate the report and store the output in the withDepositsOutput
    balanceReportWithDeposits(
        getInitialInvestment(),
        getAnnualInterest(),
        getNumYears(),
        getMonthlyDeposit(),
        withDepositsOutput
    );

	// Create two istringstream objects to read the output of the reports line by line
    istringstream noDepositsInput(noDepositsOutput.str());
    istringstream withDepositsInput(withDepositsOutput.str());

	// Declare two strings to hold the lines of output from each report one one line
    string leftLine;
    string rightLine;

    cout << endl;

	// While loop to read each line of output from both reports and print them side-by-side
    while (true) {
        bool hasLeftLine =
            static_cast<bool>(getline(noDepositsInput, leftLine));

        bool hasRightLine =
            static_cast<bool>(getline(withDepositsInput, rightLine));

		if (!hasLeftLine && !hasRightLine) { // If both reports have no more lines to read, break out of the loop
            break;
        }

		if (!hasLeftLine) { // If the left report has no more lines to read, clear the leftLine string
            leftLine.clear();
        }

		if (!hasRightLine) { // If the right report has no more lines to read, clear the rightLine string
            rightLine.clear();
        }

		// Print the left and right lines of output side-by-side with a separator in between
        cout << left << setfill(' ')
            << setw(TABLE_WIDTH) << leftLine
            << " | "
            << setw(TABLE_WIDTH) << rightLine
            << endl;
    }

    cout << endl;
}

// Run the InvestmentCalculator program, allowing the user to set values and view reports
void InvestmentCalculator::runCalculator() {
	double initInvestment = 0.0; // Initialize variables to hold the user input values
    double monthlyDep = 0.0;
    double annualInt = 0.0;
    int numYears = 0;
    int userInput = 9;

    // While loop to display the menu and process user input until the user chooses to quit
	while (userInput != 0) {
        printMenu();

		// Check if the initial investment and number of years are filled to determine if the report options can be shown
        const bool CAN_SHOW_REPORTS = (getInitialInvestment() >= 0.01) && (getNumYears() >= 1);

		// Display the menu options for the user to choose from
        cout << "\n1 - Set initial investment amount\n";
        cout << "2 - Set monthly deposit\n";
        cout << "3 - Set annual interest\n";
        cout << "4 - Set number of years\n";

		if (CAN_SHOW_REPORTS) { // Only show the report options if the initial investment and number of years are filled
            cout << "5 - View Reports side-by-side\n";
            cout << "6 - View Report without monthly deposits\n";
            cout << "7 - View Report with monthly deposits\n";
        }

        cout << "0 - Quit program\n";
        cout << endl;
        cout << "Choose an option: ";

		validMenuInput(userInput); // Validate the user input for the menu option and store it in the userInput variable
        cout << endl;

		// If the user chooses to view reports without setting an initial investment and number of years, display an error message and continue the loop
        if (!CAN_SHOW_REPORTS && (userInput >= 5) && (userInput <= 7)) {
            cout << "Please set an initial investment of at least $0.01 "
                << "and a number of years of at least 1 before viewing reports." << endl;
            continue;
        }

		// Switch statement to process the user input and call the appropriate functions
        switch (userInput) {
        case 1:
            cout << "Please enter initial investment amount: ";
			setInitialInvestment(initInvestment); // Validate the inputs, then assign the values to the InvestmentCalculator private members if valid
            cout << endl;
            break;

        case 2:
            cout << "Please enter your monthly deposit amount (0 is allowed): ";
            setMonthlyDeposit(monthlyDep);
            cout << endl;
            break;

        case 3:
            cout << "Please enter your annual interest, like 5 for 5%: ";
            setAnnualInterest(annualInt);
            cout << endl;
            break;

        case 4:
            cout << "Please enter your number of years to calculate: ";
            setNumYears(numYears);
            cout << endl;
            break;

		case 5:
			printReports(); // Print both reports side-by-side for comparison
			cout << endl;
			break;

        case 6:
			balanceReportNoDeposits(getInitialInvestment(), getAnnualInterest(), getNumYears(), cout); // Print the report without monthly deposits
            cout << endl;
            break;

		case 7:
			balanceReportWithDeposits(getInitialInvestment(), getAnnualInterest(), getNumYears(), getMonthlyDeposit(), cout); // Print the report with monthly deposits
            cout << endl;
			break;

        case 0:
			cout << "Exiting program.\n"; // Exit the program with message
            return;
        }
    }

}