#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cctype>
//#include    "Transactions.h"
using namespace std;


//generic account class 
class Account
{ 
 private:
 
	double balance;
	int num_deposits;
	int num_withdrawals;
	double annual_interest_rate;
	double montly_service_charges;
 public:
 
//**********************************************************************
//***    Function: Account Constructor
//***  Parameters: double
//***     Returns: NA
//*** Description: Accepts arguments for the balance and annual interest rate 
************************************************************************

	  Account(double bal ,double inte)
	 {
         balance=bal;
         annual_interest_rate=inte;
         num_deposits=0;
         num_withdrawals=0;
         montly_service_charges=0;
	 }


//**********************************************************************
//***    Function: Deposit
//***  Parameters: Double 
//***     Returns: NA
//*** Description: A virtual function that accepts an argument for the 
//                 amount of the deposit.Add argument to account balance 
//				   increments variable holding the deposits			
//**********************************************************************	 
	 virtual double deposit( double amount)
	 {
	 	balance+=amount;
	 	num_deposits++;
	 	return amount;
	 }
 

//**********************************************************************
//***    Function: withdraw
//***  Parameters: double
//***     Returns: NA
//*** Description: A virtual function that accepts an argument for the 
//                 amount of the withdraw. Substract argument to account balance 
//				   increments variable holding the withdraw.
//**********************************************************************	 
	 virtual double withdraw( double amount)
	 {
	 	balance-=amount;
	 	num_withdrawals++;
	 	return amount;
	 }


//**********************************************************************
//***    Function: calcInt
//***  Parameters: NA
//***     Returns: NA
//*** Description: a virtual function that updates the balance by 
//					calculating the monthly interest earned by the account
//					,and adding this imterest to the balance
//**********************************************************************
	 virtual void calcInt()
	 {
	 	double monthly_interest_rate, monthly_interest;
	 	monthly_interest_rate=(annual_interest_rate/12);
	 	monthly_interest=balance*(monthly_interest_rate/100);
	 	balance+=monthly_interest;
	
	 }

//**********************************************************************
//***    Function: monthlyProc
//***  Parameters: NA
//***     Returns: NA
//*** Description: a virtual function that substracts  the monthly
//                 service charges from the balance, call the calvInt 
//                 function , then sets the variables that hold the 
//                 number of withdraws, number of deposits and  service 
//				   charges to zero
//**********************************************************************	 
	 virtual void monthlyProc()
	 {
	 	balance-=montly_service_charges;
	 	calcInt();
	 	
	 	cout<<"Number of deposits this month: "<<getNUMdeposits()<<endl;
	 	cout<<"Number of withdraws this month: "<<getNUMwithdrawals()<<endl;
	 	cout<<"Monthly service charges: $"<<montly_service_charges<<endl;
	 	cout<<"Final Balance is : $"<<getbalance()<<endl;
	 	num_deposits=0;
        num_withdrawals=0;
        montly_service_charges=0;
	 }

//Accessor functions
	 double getbalance()
	 {
	     return balance;
	 }

	 int getNUMdeposits()
	 {
	     return  num_deposits;
	 }
	     
	 int getNUMwithdrawals()
	 {
	    return  num_withdrawals;
	 }

//Mutator functions	     
	 void addcharges( double charges)
	 {
	     montly_service_charges+=charges;
	 }

     void setinterest(double air)
     {
     	annual_interest_rate=air;
     }
     
     void initialdeposit( double amount)
	 {
	 	balance+=amount;
	 }

	 
};
#endif

