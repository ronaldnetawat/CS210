#ifndef MARKOVENTRY_H
#define MARKOVENTRY_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "bag.h"

using namespace std;

//Defining the class

class MarkovEntry
{
    public:

    MarkovEntry(string str, string filename); //Constructor Declaration

    //Member declaration
    string word() const;
    void all_successors(string filename);
    string choose_a_successor() const;
    void Display() const;

    private:
    string cur_word;
    Bag<string> successors;
};


MarkovEntry::MarkovEntry(string str, string filename) //constructor definition
{
    cur_word = str;
    all_successors(filename);
}

//Get the word
string MarkovEntry::word() const
{
    return cur_word;
}

//Displays the word and its successors
void MarkovEntry::Display () const
{
    cout << "The current word: " << cur_word << endl;
    cout << "The following are the successors: " << endl;
    successors.display();   //function defined in bag.h
}

//Returns the successor of the word
string MarkovEntry::choose_a_successor() const
{
    string successor = "";
    successors.choose(successor); //defined in bag.h
    return successor;
}

//Returns all successors from the input file
void MarkovEntry::all_successors(string filename)
{
    ifstream fin;
    fin.open(filename.data()); //opening the user-defined file
    string word;
    while (fin)
    {
        fin >> word;
        if (word == cur_word) //checking if the input is same as the current word
        { 
            fin >> word; //continue to take input
            if (word != cur_word)
            {  //the continued input is not as the same as the current word, add it to the Bag
                successors.insert(word); //calling the function defined in bag.h
            }
            else
            {
                successors.insert(""); //calling the function defined in bag.h
            }
        }
    }
}

#endif
