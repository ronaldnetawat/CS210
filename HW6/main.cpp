#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "bag.h"
#include "MarkovEntry.h"
#include <iomanip>

using namespace std;

int find_index(vector<MarkovEntry> list, string word) //this function takes in a vector and word, 
                                                      //and returns the index of that word
{
    int index;
    for (int i = 0; i < list.size(); i++)
    {
        if (word == list[i].word()) //Function defined in MarkovEntry.h
        {  
            //if the word is present at the ith index, return i
            index = i;
            
        }
    }
    return index;
}


//This function takes in a vector, sentence length, and starting position, and 
//returns a sentence of desired length by 
string create_sentence(vector<MarkovEntry> list, int sentence_length, int start_pos)
{
    int index = start_pos;
    string success_or = list[index].word();
    string sentence = "";
  
    int i = 0;
    while (i < sentence_length && success_or != "")
    {
        sentence = sentence + success_or + " ";
        success_or = list[index].choose_a_successor(); //function defined in MarkovEntry.h
        index = find_index(list, success_or);
        i++;
    }
    return sentence;
}

int main()
{
    srand(time(0));
    string filename;
    cout << "Enter file: ";
    cin >> filename;
    ifstream fin;
    fin.open(filename.data());

    while (!fin.is_open())
    {
        cout << "Invalid file name, choose another file: ";
        cin >> filename;
        fin.clear();
        fin.open(filename.data());
    }


    vector<MarkovEntry> words; //creating vector of objects from MarkovEntry
    while (fin)  //opening the file
    {
        string word;
        fin >> word;
        if (word != "")
        {
            MarkovEntry cur_word(word, filename); //creating an object of MarkovEntry
            words.push_back(cur_word); //filling the vector
        }
    }

    int sentence_length;
    cout << "Enter length of sentence (number of words): "; //defining sentence length
    cin >> sentence_length;

    int start_pos = rand()%words.size();
    cout << create_sentence(words, sentence_length, start_pos) << endl;

    return 0;
}
