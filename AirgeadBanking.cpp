//AirgeadBanking.cpp

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

#include "AirgeadbankingHeader.h"  // inherits class and attributed from header file


/*
* default constructor in case class object attributes not assigned by user
*/
UserInvestment::UserInvestment() {
    double m_init_Investment = 0.0;  // default initial investment deposit to 0
    double m_monthlyDeposit = 0.0;  // default monthly deposit amount to 0
    double m_interestRate = 0.0;  // default interest rate to 0
    double m_investmentYears = 0.0;  // default number of years to invest to 0

}

// class mutators to set object values
void UserInvestment::set_InitDeposit(double t_initDeposit) {
    m_init_Investment = t_initDeposit;  // sets initial investment amount from user input
}
void UserInvestment::set_MonthlyDeposit(double t_monthlyDeposit) {
    m_monthlyDeposit = t_monthlyDeposit;  // sets monthly deposit amount from user input
}
void UserInvestment::set_InterestRate(double t_interestRate) {
    m_interestRate = t_interestRate;  // sets interest rate from user input
}
void UserInvestment::set_InvestmentYears(int t_investmentYears) {
    m_investmentYears = t_investmentYears;  // sets number of years to invest from user input
}

// class accessors to retreive object values from class object
double UserInvestment::get_InitDeposit() const {
    return m_init_Investment;  // retrieves original investment deposit from class object
}
double UserInvestment::get_MonthlyDeposit() const {
    return m_monthlyDeposit;  // retrieves monthly deposit amount from class object
}
double UserInvestment::get_InterestRate() const {
    return m_interestRate;  // retreives designated interest rate from class object
}
double UserInvestment::get_InvestmentYears() const {
    return m_investmentYears;  // retreives set number of years to invest from class object
}