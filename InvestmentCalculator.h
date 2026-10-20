// If the header file has not been included yet, define the macro to prevent multiple inclusions
#ifndef MORENO_PROJECT_TWO_INVESTMENTCALCULATOR_H_
#define MORENO_PROJECT_TWO_INVESTMENTCALCULATOR_H_

#include <string> // Include the string header file to use the std::string class
#include <ostream> // Include the ostream header file to use the std::ostream class

// Define the InvestmentCalculator class to encapsulate the investment calculation logic and data
class InvestmentCalculator {
    private:
        // Declare private member variables
		double m_initialInvestmentAmount = 0.00;
        double m_monthlyDeposit = 0.00;
        double m_annualInterestPercentage = 0.00;
        unsigned int m_numYears = 0;

    public:
        // Declare public member functions to set the member variables
        void setInitialInvestment(double t_initialInvestment);
        void setMonthlyDeposit(double t_monthlyDeposit);
        void setAnnualInterest(double t_annualInterest);
        void setNumYears(int t_numberYears);

        // Declare a public member function to format money values
		std::string formatMoney(double t_amount) const;

		// Declare public member functions to get the private member variables
        double getInitialInvestment();
        double getMonthlyDeposit();
        double getAnnualInterest();
        int getNumYears();
        int getNumMonths();

		// Declare public member functions to validate user input
        bool validDoubleInput(double& t_inputDouble, double t_minimum = 0.01);
        bool validIntInput(int& t_inputInt);
        bool validMenuInput(int& t_userInput);

		// Declare public member functions to print the menu and reports
        void printMenu();
        void printUserMenuTopBorder();

		// Declare public member functions to calculate the year-end balance and convert years to months
        double calcYearEndBalance(
            double t_initialInvestment,
            double t_annualInterest,
            int t_numberYears,
            double t_monthlyDeposit = 0.0);

        int convertYearToMonths(int t_numYears);

		// Declare public member functions to print the report header and balance reports
        void printReportHeader(
            const std::string& t_title,
            std::ostream& t_output);
        void balanceReportNoDeposits(
            double t_initialInvestment,
            double t_annualInterest,
            int t_numYears,
            std::ostream& t_output);
        void balanceReportWithDeposits(
            double t_initialInvestment,
            double t_annualInterest,
            int t_numYears,
            double t_monthlyDeposit,
            std::ostream& t_output);

		// Declare a public member function to print both reports side-by-side
        void printReports();

		// Declare a public member function to run the InvestmentCalculator program
        void runCalculator();
};



#endif // MORENO_PROJECT_TWO_INVESTMENTCALCULATOR_H_