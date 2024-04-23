//main.cpp

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

#include "AirgeadBanking.cpp"
#include "AirgeadBankingPrint.cpp"
#include "AirgeadBankingHeader.h"  // inherits class and attributed from header file

/*
* main function, accepts user input and sets directive of additional 
* class and functions to process the input values received
*/
int main() {
    // main function declared variables for user input values and program looping
    double initDeposit;
    double monthlyDeposit;
    double interestRate;
    double yearsInvested;

    char recalculate;
    bool runProgram = true;

    /*
    * function call to investment screen with blank values
    */
    PrintInitial();
    cin.ignore();  // input ignore to allow for "press any button to continue..."
    
    /*
    * main program while loop, allows for continually retrying new investment values 
    * until user decides to exit
    */
    while (runProgram == true) {

        UserInvestment investProfile;  // class object declaration

        // initial deposit amount received from user and assigned to class object
        cout << "Please enter initial investment: \n";
        cin >> initDeposit;
        investProfile.set_InitDeposit(initDeposit);

        // monthly deposit amount received from user and assigned to class object
        cout << "Please enter your expected monthly deposit: \n";
        cin >> monthlyDeposit;
        investProfile.set_MonthlyDeposit(monthlyDeposit);

        /* 
        * interest rate received from user, verification and mutation performed if necessary to uniform value set to class object.
        * allows for user input of either whole number percentage value or decimal value (ie 5 or 0.05)
        */
        cout << "Please enter interest rate: \n";
        cin >> interestRate;
        if (interestRate <= 1) {
            investProfile.set_InterestRate(interestRate);
        }
        else if (interestRate > 1) {
            interestRate /= 100.0;
            investProfile.set_InterestRate(interestRate);
        }

        // number of years to calculate received from user and assigned to class object
        cout << "Please enter number of years to invest: \n";
        cin >> yearsInvested;
        investProfile.set_InvestmentYears(yearsInvested);

        cout << endl;

        /*
        * PrintUserInvestment function call to print new investment screen with user entered values for review
        */
        PrintUserInvestment(investProfile.get_InitDeposit(), investProfile.get_MonthlyDeposit(), investProfile.get_InterestRate(), investProfile.get_InvestmentYears());
        cin.ignore();

        cout << endl;

        /*
        * PrintROIBreakdown function call to print additional yearly breakdown screen
        */
        PrintROIBreakdown(investProfile.get_InitDeposit(), investProfile.get_MonthlyDeposit(), investProfile.get_InterestRate(), investProfile.get_InvestmentYears());
        cin.ignore();
        

        /*
        * request to user to rerun program for new investment calculations
        */
        cout << "\nWould you like to adjust the calulation? (y/n)\n";
        cin >> recalculate;

        //loop handles user input to verify input and either terminate program or restart
        while (!isblank(recalculate)) {
            if (recalculate == 'y' || recalculate == 'Y') {  // if 'y' rerun program
                runProgram = true;
                break;
            }
            else if (recalculate == 'n' || recalculate == 'N') {  // if 'n' thank user and terminate program
                cout << "\nThank you for investing with Airgead Banking!\n";
                runProgram = false;
                break;
            }
            else {  // if anything other than 'y' or 'n' then reject input and reiterate input requirement. request input again
                cout << "Please enter only 'y' or 'n' \n";
                cout << "Would you like to adjust the calulation? (y/n)\n";
                cin >> recalculate;
            }
        }
    }

    return 0;
}