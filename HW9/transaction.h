// class that defines a transction as a name, an enter time, and an
// amount of time to perform the transaction
#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>

using namespace std;

class Transaction{
public:
    // default constructor.  Uses empty string for name, entrance time 1,
    // transaction time 1
    Transaction();

    void Set_Name(string n);

    void Set_Transaction_Time(int t);

    string Get_Name() const;

    int Get_Transaction_Time() const;

private:
    string my_transaction_name;

    int my_transaction_time;
};

#endif
