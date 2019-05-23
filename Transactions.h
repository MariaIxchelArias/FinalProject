
#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;

//class definition
class Transactions//structure tag
{
    //class attribuates
    private:
    
        struct NewTransaction
        {
            
            string transactionName;
            double amount;
            double cbalance;
            string datetime;
            struct NewTransaction *next;
        };
        
        NewTransaction *head;


    // member functions
    public:
        
        //Constructors
        Transactions()//constructor number 1 - default no arguments
        {
            head = nullptr;
            
        }
        
        ~Transactions();//destructor 
  
        //getter Functions
        void appendNode(double,double, string,string) ;
        void displayList() ;
         
};
#endif