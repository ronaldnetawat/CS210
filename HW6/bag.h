#ifndef BAG_H
#define BAG_H

#include <vector>
#include <time.h>

using namespace std;

// "T" is out parameterized type that we're making a bag out of
// Whenever you see "T", that means "the type of the elements of the bag"
template <typename T>
class Bag{
 public: 

  Bag(); // default constructor

  Bag(const Bag<T>& other); //copy constructor

  // functions to get information about the bag
  int size() const;
  int count(const T& item) const;
  bool is_empty() const;

  // we'll talk about choose in the lab

  // fuctions to modify the bag
  void insert(const T& item);
  bool remove(const T& item); // returns true if successful, false otherwise
  void display() const;
  bool choose(T& item) const;
  T SelectItem(int pos) const;
  void sort();
  vector<T> toVector() const;
  template <typename R>
    bool operator<(const Bag<R>& other);

 
 private: 

  vector<T> bag_elements;
};




// Since this is a template class, we need to write the implementations of the
// member functions here, in the .h file.


// default constructor, initializes the vector to be empty
template <typename T>
Bag<T>::Bag(){
  bag_elements.resize(0);
}

// size function: returns the number of elements currently in the bag
template <typename T>
int Bag<T>::size() const{
  return bag_elements.size();
}

// count function: returns the number of elements that are equal to "item"
template <typename T>
int Bag<T>::count(const T& item) const{
  int num_matches = 0;
  for(int i = 0; i < bag_elements.size(); i++)
    if(bag_elements[i] == item)
      num_matches++;

  return num_matches;
}

// is_empty: returns true if the bag has 0 elements, false otherwise
template <typename T>
bool Bag<T>::is_empty() const{
  return (size() == 0);
}

// insert: adds "item" to the bag by adding the new item to the private vector
template <typename T>
void Bag<T>::insert(const T& item){
  bag_elements.push_back(item);
}

// remove: removes one occurrence of "item" from the bag, if it exists
// returns true if there was an item removed, false if not
template <typename T>
bool Bag<T>::remove(const T& item){
  bool found = false;
  int i = 0;
  while(!found && i <bag_elements.size()){
    if(bag_elements[i] == item)
      found = true;
    else
      i++;
  }
  
  if(found){
    bag_elements[i] = bag_elements[bag_elements.size()-1];
    bag_elements.resize(bag_elements.size()-1);
  }
  return found;
}

//display: displays the items in the bag
template <typename T>
void Bag<T>::display() const
{
  for (int i = 0; i < bag_elements.size(); i++)
  {
    cout << bag_elements[i] << endl;
  }
}



//select_item: selects an item at a position (pos)
//in the bag
template <typename T>
T Bag<T>::select_item (int pos) const
{
  return bag_elements[pos];
}

/*Bag: another constructor of the class
to create an object by copying items from
the given Bag*/
template <typename T>
Bag<T>::Bag(const Bag<T>& other)
{
  bag_elements.resize(other.size());
  for (int i = 0; i < other.size(); i++)
  {
    bag_elements[i] = other.bag_elements[i];
  }
}

/*choose_item: if the bag is empty, return false. Else it
//chooses a random item from the bag and returns true*/
template <typename T>
bool Bag<T>::choose_item(T& item) const
{
  srand(time(0));
  if(is_empty())
    return false;
  else
  {
    item = bag_elements[rand()%bag_elements.size()];  
    return true;
  }

}

//sort: sorts the bag using bubble sort (works on numerical data types)
template <typename T>
void Bag<T>::sort()
{
  for(int i = 0; i < bag_elements.size() - 1; i++)
  {
    for (int j = (i+1); j < bag_elements.size(); j++)
    {
      if (bag_elements[i] > bag_elements[j])
      {
        T temp = bag_elements[i];
        bag_elements[i] = bag_elements[j];
        bag_elements[j] = temp;
      }
    }
  }
}

//toVector: copies the items present in the bag
//and returns a vector
template <typename T>
vector<T> Bag<T>::toVector() const
{
  vector<T> elements;
  elements.resize(bag_elements.size());
  for (int i = 0; i < bag_elements.size(); i++)
  {
    elements[i] = bag_elements[i];
  }
  return elements;
}

//operator<: compares the sizes of the Bag object and with 
//another Bag object provided and returns true if its size is 
//less than the size of the Bag object provided, else
//returns false
template <typename T>
template <typename R>
bool Bag<T>::operator<(const Bag<R>& other)
{
  if (bag_elements.size() < other.bag_elements.size())
  {
    return true;
  }
  else
  {
    return false;
  }
}
    
#endif
