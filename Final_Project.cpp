/*
COMSC 165-8271
05/21/19
Maria Ixchel Arias Cruz 

FINAL PROJECT - Bank Accounts 


*/

#include <chrono> 
#include <ctime> 
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cctype>
#include "Transactions.h"
#include "Transactions.cpp"
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

using namespace std;


int main()
{
	
	//variable definition 
    char userOption;
    string firstName, lastName, doBirth, phone, email, clientLName,clientFName; 
    double  interestrate,deposit_amount, withdraw_amount;
    int initial=0;
    
    //variable definition for linkedlist
    double deposittrans, withdrawtrans, withdrawtrans2, cbalance;
    string depositStr="Deposit";
    string withdrawStr="Withdraw";
    string dateandtime;
    
    //Instantiation of an array of objects class Contact. And Initialization of first 3.
    //using different constructors
    
    cout<<"Savings and Checking account"<<endl;
    cout<<"User data entry"<<endl;
    
    
    do{
        cout<<"\nEnter initial deposit of you savings account (min $1000): ";
        cin>>deposit_amount; 
    }while(deposit_amount<1000);
    if (deposit_amount>=1000&&deposit_amount<2000)
    {
        interestrate=10;
        cout<<"\nGreat - your annual interest rate is "<<interestrate <<" percent"<<endl;
    }
    else if(deposit_amount>=2000&&deposit_amount<4000)
    {
        interestrate=20;
        cout<<"\nGreat - your annual interest rate is "<<interestrate <<" percent"<<endl;
    }
    else 
    {
    interestrate=30;
    cout<<"\nGreat - your annual interest rate is "<<interestrate <<" percent"<<endl;
    }
    
    //instantiation of a class SavingsAccount
    SavingsAccount client(deposit_amount,interestrate);
    cbalance=client.getbalance();
    cout<<"Your balance is : "<<cbalance<<endl;
    
    //converting current time to string
    auto timenow1 =  chrono::system_clock::to_time_t(chrono::system_clock::now()); 
    dateandtime = static_cast<string>(ctime(&timenow1));
    //creating a transaction 
    Transactions newTransaction;
    newTransaction.appendNode(deposit_amount,cbalance,"Initial deposit", dateandtime);
                                        
                                    

    
 
    do{
        cout<<"\nEnter initial deposit of you savings account (min $500): ";
        cin>>deposit_amount; 
    }while(deposit_amount<500);
    
    if (deposit_amount>=500&&deposit_amount<1000)
    {
        interestrate=5;
        cout<<"\nGreat - your annual interest rate is "<<interestrate <<" percent"<<endl;
    }
    else if(deposit_amount>=1000&&deposit_amount<2000)
    {
        interestrate=7;
        cout<<"\nGreat - your annual interest rate is "<<interestrate <<" percent"<<endl;
    }
    else 
    {
        interestrate=10;
        cout<<"\nGreat - your annual interest rate is "<<interestrate <<" percent"<<endl;
    }

    //instantiation of a class CheckingAccount
    CheckingAccount client1(deposit_amount,interestrate);
    cbalance=client1.getbalance();
    cout<<"Your balance is : "<<cbalance<<endl;
    
    //converting current time to string
    auto timenow2 =  chrono::system_clock::to_time_t(chrono::system_clock::now()); 
    dateandtime = static_cast<string>(ctime(&timenow2));
    //creating a transaction 
    Transactions newTransaction1;
    newTransaction1.appendNode(deposit_amount,cbalance,"Initial deposit", dateandtime);
    

    ///User Menu
        cout << string(5, '\n');   
        cout<<"Bank Accounts User MENU"<<endl<<endl;
        cout<<"1 Savings account "<<endl;
        cout<<"2 Checking account "<<endl;
        cout<<"E Exit"<<endl;
        cout<<"User selection: ";
        cin>>userOption;
        cin.ignore();
    
    //while uose option is different from Exit continue    
    while(toupper(userOption)!='E')
    {
         //make user option entry uppercase  
        switch(toupper(userOption))
        {
            case '1':
            {
                    ///User Menu
                    cout << string(5, '\n');   
                    cout<<"Savings Account MENU"<<endl<<endl;
                    cout<<"1 Deposit "<<endl;
                    cout<<"2 Withdraw "<<endl;
                    cout<<"3 Monthly report "<<endl;
                    cout<<"E Exit"<<endl;
                    cout<<"User selection: ";
                    cin>>userOption;
                    cin.ignore();
                    
                    //while uose option is different from Exit continue       
                    while(toupper(userOption)!='E')
                    {
                        //make user option entry uppercase 
                        switch(toupper(userOption))
                            {
                                case '1':
                                {
                                    
                                    cout<<"Amount to be deposit: ";
                                    cin>>deposit_amount;
                                    deposittrans=client.deposit(deposit_amount);
                                    cbalance=client.getbalance();
                                    cout<<"Your balance is : "<<cbalance<<endl;
                                    
                                    //converting current time to string
                                    auto timenow3 =  chrono::system_clock::to_time_t(chrono::system_clock::now()); 
                                    dateandtime = static_cast<string>(ctime(&timenow3));
                                    //creating a transaction 
                                    newTransaction.appendNode(deposittrans,cbalance, depositStr, dateandtime);
                                    
                                    cout<<"Your balance is : "<<client.getbalance()<<endl;
                                    break;
                                }
                                case '2':
                                {
                                cout<<"Your Savings account balance is:  "<<client.getbalance()<<endl;
                                cout<<"Introduce the amount you want to withdraw: ";
                                cin>>withdraw_amount; 
                                    //calling class member functions
                                withdrawtrans=client.withdraw(withdraw_amount);
                                cbalance= client.getbalance();   
                                    //converting current time to string
                                    auto timenow4 =  chrono::system_clock::to_time_t(chrono::system_clock::now()); 
                                    dateandtime = static_cast<string>(ctime(&timenow4));
                                    //creating a transaction 
                                    newTransaction.appendNode(withdrawtrans,cbalance,withdrawStr, dateandtime);
                                    
                                
                
                                break;
                                }
                                case '3':
                                {
                                     cout<<" Transactions per month details"<<endl<<endl;
                                    newTransaction.displayList();
                                    client.monthlyProc();
                                    
                                    break;
                                }
                                
                                
                                
                            } 
                    ///User Menu
                    cout << string(5, '\n');        
                    cout<<"Savings Account MENU"<<endl<<endl;
                    cout<<"1 Deposit "<<endl;
                    cout<<"2 Withdraw "<<endl;
                    cout<<"3 Monthly report "<<endl;
                    cout<<"E Exit"<<endl;
                    cout<<"User selection: ";
                    cin>>userOption;
                    cin.ignore();       
                    }
            break;
            }    
            case '2':
            
            {
                    ///User Menu
                    cout << string(5, '\n');
                    cout<<"Checkings Account MENU"<<endl<<endl;
                    cout<<"1 Withdraw (check written)"<<endl;
                    cout<<"2 Monthly report "<<endl;
                    cout<<"E Exit"<<endl;
                    cout<<"User selection: ";
                    cin>>userOption;
                    cin.ignore();
                    
                    //make user option entry uppercase 
                    while(toupper(userOption)!='E')
                    {  
                        //make user option entry uppercase  
                        switch(toupper(userOption))
                            {
                                case '1':
                                {
                                cout<<"Your Savings account balance is:  "<<client1.getbalance()<<endl;
                                cout<<"Introduce the amount you want to withdraw: ";
                                cin>>withdraw_amount; 
                                    //calling class member functions
                                withdrawtrans2=client1.withdraw(withdraw_amount);
                                cbalance=client1.getbalance();
                                cout<<"Your balance is : "<<cbalance<<endl;
                                
                                    //converting current time to string
                                    auto timenow5 =  chrono::system_clock::to_time_t(chrono::system_clock::now()); 
                                    dateandtime = static_cast<string>(ctime(&timenow5));
                                    //creating a transaction 
                                    newTransaction1.appendNode(withdrawtrans2,cbalance,withdrawStr, dateandtime);
                                    
                                
                
                                break;
                                }
                                case '2':
                                {
                                     cout<<" Transactions per month details"<<endl<<endl;
                                    newTransaction1.displayList();
                                    client1.monthlyProc();
                                    
                                    break;
                                }
                                
                                
                                
                            } 
                    ///User Menu
                    cout << string(5, '\n');        
                    cout<<"Checking Account MENU"<<endl<<endl;
                    cout<<"1 Withdraw "<<endl;
                    cout<<"2 Monthly report "<<endl;
                    cout<<"E Exit"<<endl;
                    cout<<"User selection: ";
                    cin>>userOption;
                    cin.ignore();       
                    }
            break;
            }   
                
        }
        cout << string(5, '\n');
        cout<<"Bank Accounts User MENU"<<endl<<endl;
        cout<<"1 Savings account "<<endl;
        cout<<"2 Checking account "<<endl;
        cout<<"E Exit"<<endl;
        cout<<"User selection: ";
        cin>>userOption;
        cin.ignore();
    }

cout<<"goodbye"<<endl;;
    
 return 0;   
    
}