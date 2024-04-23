//AirgeadBankingHeader.h

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

#ifndef PROJECTTWO_AIRGEADBANKING_H
#define PROJECTTWO_AIRGEADBANKING_H

#include <iostream>
#include <iomanip>
using namespace std;

/*
* class declaration for UserInvestment object creation
*/
class UserInvestment {

    public:
        // default constructor, 
        UserInvestment();

        // class mutators to set user initialized values
        void set_InitDeposit(double t_initDeposit);
        void set_MonthlyDeposit(double t_monthlyDeposit);
        void set_InterestRate(double t_interestRate);
        void set_InvestmentYears(int t_investmentYears);

        // class accessors to retreive class object values
        double get_InitDeposit() const;
        double get_MonthlyDeposit() const;
        double get_InterestRate() const;
        double get_InvestmentYears() const;

    private:
        // private data members only used within class
        double m_init_Investment;
        double m_monthlyDeposit;
        double m_interestRate;
        double m_investmentYears;


};

#endif