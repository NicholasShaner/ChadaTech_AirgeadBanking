//AirgeadBankingPrint.cpp

/***************
 *  CS-210 5-3 Project Two
 *  AirgeadBanking.cpp
 *
 *  Nicholas Shaner
 *  SNHU
 *  CS-210-R4727
 *  Prof. Cory Thoma
 *  April 7, 2024
 * 
 ***************/

#include "AirgeadBankingHeader.h"  // inherits class and attributed from header file

/*
* print function to output initial investment screen with
* blank values as requested
*/
void PrintInitial() {
    cout << "**********************************\n";
    cout << "**********  Data Input  **********\n";
    cout << "Initial Investment Amount: \n";
    cout << "Monthly Desposit: \n";
    cout << "Annual Interest Rate: \n";
    cout << "Number of Years Invested: \n";
    cout << "Press any key to continue...\n";
}

/*
* print function to output new investment screen with user initialized values included.
* parameter requirements of four initial value requests from user
*/
void PrintUserInvestment(double initInvestment, double monthlyDeposit, double interestRate, double investmentYears) {
    cout << "**********************************\n";
    cout << "**********  Data Input  **********\n";
    // fixed, setprecision used to specify #.## format. allows user to enter ie. '1' and print '1.00' 
    cout << "Initial Investment Amount: $" << fixed << setprecision(2) << initInvestment << endl;
    cout << "Monthly Desposit: $" << monthlyDeposit << endl;
    // setprecision override to allow for 3 digit percentage rates (ie 1.5% is 0.015 decimal value), setfill fills unused spaces with 0
    cout << "Annual Interest Rate: " << setprecision(3) << setfill('0') << interestRate << "%" << endl;
    // setprecision override again to remove decimal from year value (realy just aesthetics)
    cout << "Number of Years Invested: " <<setprecision(0) << investmentYears << endl;
    cout << "Press any key to continue...\n";
    cin.ignore(); // input ignore method to allow for "press any key to continue..."
}

/*
* print function called to print yearly investment table. required parameters again of four user initialized values
* (honestly this took probably 70% of the time spent on this program to figure out)
*/
void PrintROIBreakdown(double initInvestment, double monthlyDeposit, double interestRate, double investmentYears) {
    // function specific variables
    double EndYearBalance = initInvestment;
    double monthlyROI = 0;
    double yearlyROI = 0;

    // print statement for table without any additional monthly contributions
    cout << "    Balance and Interest Without Additional Monthly Deposits    \n";
    cout << "================================================================\n";
    cout << "  Year       Year End Balance         Year End Earned Interest  \n";
    cout << "-----------------------------------------------------------------\n";
    // for loop to process table data for each year, up to number of years initialized by user
    for (int i = 0; i < investmentYears; i++) {
        // nested for loop to process monthly compounded interest 
        for (int j = 0; j < 12; j++) {
            monthlyROI = EndYearBalance * (interestRate / 12.0);  // calculates monthly interest return ( '/ 12' for monthly compounding)
            EndYearBalance += monthlyROI;  // reassigns EndYearBalance as monthly interest is compounded
            yearlyROI += monthlyROI;  // tracks yearly ROI across 12 months to output to table
        }

        // continues print statement to print calculated values to table
        cout << "   " << i + 1;
        cout << "           $";
        // precision, set width and alignment format specifiers set. fixed allows to carry format to additional output statements
        cout << fixed << setprecision(2) << setw(30) << left << setfill(' ') <<EndYearBalance;
        cout << "$";
        // format specifiers set to override original formatters while carrying others 
        cout << setw(9) << setfill(' ') << yearlyROI;
        yearlyROI = 0;
        cout << endl;
    }

    // reinitialize function variables to reset values for second investment table
    EndYearBalance = initInvestment;
    monthlyROI = 0;
    yearlyROI = 0;
    
    // print statement for table with additional monthly contributions
    cout << "\n";
    cout << "     Balance and Interest With Additional Monthly Deposits      \n";
    cout << "================================================================\n";
    cout << "  Year       Year End Balance         Year End Earned Interest  \n";
    cout << "-----------------------------------------------------------------\n";
    /*
    * same for loop and nested for loop as used previously, with only 
    * addition of monthlyDeposit value received from user
    */
    for (int i = 0; i < investmentYears; i++) {
        for (int j = 0; j < 12; j++) {
            EndYearBalance += monthlyDeposit;
            monthlyROI = EndYearBalance * (interestRate / 12.0);
            EndYearBalance += monthlyROI;
            yearlyROI += monthlyROI;
        }
        cout << "   " << i + 1;
        cout << "           $";
        cout << fixed << setprecision(2) << setw(30) << left << setfill(' ') <<EndYearBalance;
        cout << "$";
        cout << setw(9) << setfill(' ') << yearlyROI;
        yearlyROI = 0;
        cout << endl;
    }
    cout << "Press enter...\n";
}