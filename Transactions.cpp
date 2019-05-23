#include	<iostream>
#include	<cstdlib>
#include	<cmath>
#include    "Transactions.h"
using namespace std;

//add a new node at the end of the list
//or create a new node 

void Transactions::appendNode(double amount, double balance,string action, string datetime ) 
{
    NewTransaction *newNode; // a new node
    NewTransaction *nodePtr; //to traverse the list
    
    newNode = new NewTransaction;
    newNode->amount=amount;
    newNode->cbalance=balance;
    newNode->transactionName=action;
    newNode->datetime=datetime;
    newNode->next=nullptr;
   

        
    /// if there is no nodes in the list 
    //make a new node --> the first node 
    if(!head)
    {
        head=newNode;
        cout<<"Transaction was completed \n"<<endl;
    }
    else//othetwise, inser newnode at the end 
    {
        //Initialize node ptr to head of the list 
        nodePtr=head;
        
        //find last node in the list 
        while(nodePtr->next)
            nodePtr=nodePtr->next;
       
        //insert new Node as the last node
            nodePtr->next= newNode;
            cout<<"Transaction was completed \n"<<endl;
            

    }

    
}

     

void Transactions::displayList() 
{
    NewTransaction *nodePtr;
    
    //position nodePtr at the head of the list 
    nodePtr=head;
    int count = 0;

    while(nodePtr)// traverse the list while nodeptr points to a node 
    {
        count++;
        //display values on this node
        cout<<count<< " ";
        cout<<left<<setw(10)<<" Transaction Type: " <<setw(15)<< nodePtr-> transactionName;
        cout<<left<<setw(10)<<" Amount: $"  <<setw(15)<< nodePtr-> amount ;
        cout<<left<<setw(10)<<" Current Balance: $"  <<setw(15)<< nodePtr-> cbalance ;
        cout<<left<<setw(10)<<" Date and Time: "<<setw(15)<<nodePtr-> datetime<<endl<<endl;
        nodePtr=nodePtr->next;
    }
}


Transactions::~Transactions() 
{
    NewTransaction *nodePtr;//traver  the list
    NewTransaction *nextNode;//to point to the next node
    //position nodePtr at the head of the list 
    nodePtr=head;
    while(nodePtr!=nullptr)// traverse the list while nodeptr points to a node 
    {
        //save a pointer to the next node 
        nextNode = nodePtr->next;
        //deletr thr current node
        delete nodePtr;
        //position nodePtr at the next node 
        nodePtr = nextNode;
        
        
    }
    cout<<"destructor in action"<<endl;

}

