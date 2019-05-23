# Project Title
Bank Account Project 
by: Maria Ixchel Arias Cruz

This program demostrates the use of classes to create a bank account program. 
The program ask the user the the amounts of deposits and withdrawals for a savings
account and cheking account.

The program use the next concepts:
 Loopings 
 Conditional statements
 Classes
 Inheritance
 Polymorphism
 type casting
 link lists 

The program use the generic class Account to hold the next information from a 
bank account:Balance, Number of deposits per month , Number of withdrawals, 
annual interest rate and Montly Service Charges .The program will also use two 
derived classes: SavingsAccount and CheckingAccount.Savings account has the menber
functions to check if balance of saving account falls below $25; moreover,
SavingsAccount member functions will check if the account is active or innactive 
before doing any transaction. SavingsAccount member function will add a service 
charge $1 for each withdraw above 4.

The second derived class Checking account will have the functions to make available 
written check withdraw. If balance goes below $0 a service charge of 15 will be 
taken from the account; moreover, there will be a monthly fee of $5 plus $.10 per 
withdraw.

The base class Account has the next member functions:
Constructor:Accepts arguments for the balance and annual interest rate 

deposits: A virtual function that accepts an argument for the amount of the 
deposit.Add argument to account balance  increments variable holding the deposits	

withdrawals: A virtual function that accepts an argument for the amount of the 
withdraw. Substract argument to account balance increments variable holding the 
withdraw.

calcInt: a virtual function that updates the balance by 	calculating the 
monthly interest earned by the account	,and adding this imterest to the balance

MonthlyProc:a virtual function that substracts  the monthly service charges 
from the balance, call the calvInt function , then sets the variables that hold 
the  number of withdraws, number of deposits and  service charges to zero


#Getting Started
If using Visual Studio

1. Click the Windows "Start" button and select "All Programs." Click 
2. "Microsoft .NET Express," then select "Visual Studio Express" to open the 
software.

2. Click the "File" menu item, then select "Open." Double-click the CPP file 
to load the source code in Visual Studio.

Load the all the files in the same directory.
 Final_Project.cpp
 Account.h
 SavingsAccount.h
 CheckingAccount.h
 Transactions.h
 Transactions.cpp
 
3.Click the "Build" menu item and select "Build Solution." The software compiles
the code and creates the EXE file.

4. Select the "Run" button. The compiler runs the executable file, so you can 
5. review the results of the C++

# Built With
AWS Cloud9 C++

#Versioning
Version 1 05/23/2019

#Authors
Maria Ixchel Arias Cruz, student at DVC Campus Pleasant Hill.
COMSC 165-8271


