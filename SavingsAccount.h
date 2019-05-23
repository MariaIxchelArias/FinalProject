#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cctype>
#include "Account.h"
//#include    "Transactions.h"
using namespace std;

//savingaccount class derived from Account class
class SavingsAccount : public Account
{ 
 private:
    bool status;
 public:
//**********************************************************************
//***    Function: constructor SavingsAccount
//***  Parameters: double amount double rate
//***     Returns: NA
//*** Description: Set initial account flag to true, and call base class
//                 constructor 
//**********************************************************************
     SavingsAccount(double amount, double rate):Account(amount,rate)
     {
     	status=true;
     }

//**********************************************************************
//***    Function: isactive
//***  Parameters: NA
//***     Returns: NA
//*** Description: Check if the balance of savings account fall below $25, if yes 
//                 account becomesinactive. No more withdrwas are posible until the 
//				   balance is raised above $25, then account becomes active again. 
//**********************************************************************
 	 bool isactive()
	 {
	 	if(getbalance()<25)
	 	{
	 	  status=false;
	 	  cout<<"INACTIVE Account"<<endl;
	 	  cout<<"No transactions available"<<endl;
	 	  return status;
	 	}
	 	else
	 	{
	 	status=true;
	 	cout<<"ACTIVE Account"<<endl;
	 	return status;
	 	}
	 }

//**********************************************************************
//***    Function: withdraw
//***  Parameters: double am - amount
//***     Returns: NA
//*** Description: checks if account is active before withdraw is made
//				   No withdraw are posible until account is active
//					withdraw is made using base class version
//**********************************************************************	 
	 double withdraw( double am)
	 {
        double amount=am;
        double amountwithdraw;
        //isactive();
	 	if(isactive())
	 	{
	 		if(getbalance()>amount)
	 		{
	 			
	 		    amountwithdraw=Account::withdraw(amount);
	 		   
	        }
	 	    else
	 	   {   
	 	   		cout<<"Amount Available: $" << getbalance()<<endl;
	 	   		cout<<"Amount Withdrawed: $" << getbalance()<<endl;
	 			amountwithdraw=Account::withdraw(getbalance());
	 		
	 		}
	 	}
	 	return amountwithdraw;
	  }
	  
 
//**********************************************************************
//***    Function: deposit
//***  Parameters: double amount
//***     Returns: NA
//*** Description:
//**********************************************************************	 
	 double deposit( double amount)
	 {
		double check=0.0;
		double amountdeposited;
		check=getbalance()+amount;
		if(check>25)
		{
			
			status=true;
			amountdeposited=Account::deposit(amount);
			
		}
	 	isactive();
      return amountdeposited;
	  }
 	 
	 void monthlyProc()
	 {

	 	if(getNUMwithdrawals()>4)
	 	{
	 		int num;
	 		double charges;
	 		num=getNUMwithdrawals()-4;
	 		charges=1*num;
	 		cout<<"Extra charges: $"<<charges<<endl;
	 		Account::addcharges(charges);
	 	}
	 	Account::monthlyProc();
	 }

};
#endif

