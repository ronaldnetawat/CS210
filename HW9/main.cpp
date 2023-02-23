#include <iostream>
#include <string>
#include <vector>
#include "transaction.h"
#include "queue.h"
using namespace std;

int main()
{
    int clients; //holds the number of transactions
    cout << "How many clients do you want to enter? ";
    cin >> clients;

    Queue<Transaction> queue; //queue to hold the transactions
    Transaction transaction; //Transaction variable to hold the transaction data

    vector<int> transaction_times;
    vector<string> names;
    for (int i = 0; i < clients; i++) //get input and store transaction data in the queue
    {
        string name;
        int time;

        cout << "Enter client's name:  ";
        cin >> name;
        transaction.Set_Name(name);
        names.push_back(name);
        cout << "Enter transaction time: ";
        cin >> time;
        transaction.Set_Transaction_Time(time);
        transaction_times.push_back(time);

        queue.Enqueue(transaction); //insert the transaction to the queue
    }

    
    for(int i = 0; i < clients; i++)
    {
        cout << "Transaction " << names[i] << " leaves at time ";
        cout << transaction_times[i] + transaction_times[i-1] << endl;
    }


}
