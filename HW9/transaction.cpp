#include "transaction.h"
#include <iostream>

// default constructor.  Uses empty string for name, entrance time 1,
// transaction time 1
Transaction::Transaction(){
    my_transaction_name = "";

    my_transaction_time = 1;
}

void Transaction::Set_Name(string n){
    my_transaction_name = n;
}



void Transaction::Set_Transaction_Time(int t){
    my_transaction_time = t;
}


string Transaction::Get_Name() const{
    return my_transaction_name;
}



int Transaction::Get_Transaction_Time() const{
    return my_transaction_time;
}
