#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cctype>
#include "Account.h"
//#include    "Transactions.h"
using namespace std;

//CheckingAccount class derived from Account class
class CheckingAccount : public Account
{ 
 private:
    bool status;
 public:
 
//**********************************************************************
//***    Function: constructor CheckingAccount
//***  Parameters: double amount double rate
//***     Returns: NA
//*** Description: Set initial account flag to true, and call base class
//                 constructor 
//**********************************************************************
     CheckingAccount(double amount, double rate):Account(amount,rate)
     {
     	status=true;
     }

//**********************************************************************
//***    Function: withdraw
//***  Parameters: double am
//***     Returns: NA
//*** Description: 
//**********************************************************************
	 double withdraw( double am)
	 {
	 	double check;
	 	double amountwithdraw;
		check=getbalance()-am;
	 	if(check>0)
	 	{
	 		amountwithdraw=Account::withdraw(am);
	 		Account::addcharges(.10);
	 	}
	 	else
	 	{
	 		cout<<"Withdraw unavailable"<<endl;
	 		Account::addcharges(15);
	 	}
	 	return amountwithdraw;
	  }

//**********************************************************************
//***    Function:
//***  Parameters:
//***     Returns:
//*** Description:
//**********************************************************************
	 void monthlyProc()
	 {
	 	double charges=5.0;
	 	Account::addcharges(charges);
	 	Account::monthlyProc();
	 }

};
#endif