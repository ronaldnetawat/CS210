#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "doublenode.h"

template <typename T>
class Queue{
public:
    //Constructor- creates an empty queue
    Queue();

    // Destructor- removes and deletes all nodes from the queue.
    // uncomment this when you have Dequeue and Is_Empty written
    ~Queue();

    // Copy constructor- makes a deep copy
    Queue(const Queue<T>& other);

    // enqueue- inserts an item into the back of the queue
    void Enqueue(const T& new_val);

    // dequeue- removes an item from the front of the queue
    // sets the error state if the queue is empty
    T Dequeue();

    // returns true if queue is empty
    bool Is_Empty();

    // returns true if the last operation caused an error- false otherwise
    bool Error() const;
private:
    DoubleNode<T>* Front;
    DoubleNode<T>* Back;
    bool last_error;
};

// Default constructor- sets all pointers to NULL
template <typename T>
Queue<T>::Queue(){
    Front = NULL;
    Back = NULL;
}

// Copy constructor- makes a deep copy of the parameter
template <typename T>
Queue<T>::Queue(const Queue<T>& other){
    if(other.Front == NULL){
        Front = NULL;
        Back = NULL;
    }
    else{
        Front = new  DoubleNode<T>;
        Front->set_item(other.Front->get_item());
        Front->set_prev(NULL);
        DoubleNode<T>* p = Front;
        DoubleNode<T>* other_p = other.Front->get_next();
        while(other_p != NULL){
            DoubleNode<T>* new_node = new DoubleNode<T>;
            new_node->set_item(other_p->get_item());
            p->set_next(new_node);
            new_node->set_prev(p);
            p = new_node;
            other_p = other_p->get_next();
        }
        p->set_next(NULL);
        Back = p;
    }

}

// destructor.  Commented out because it uses functions you'll write in the lab
template <typename T>
Queue<T>::~Queue(){
  while(!Is_Empty()){
    Dequeue();
  }
}

template <typename T>
bool Queue<T>::Error() const { //Defining the error function:
    return last_error;          //checks if an error was caused by the previous step
}

template <typename T>
bool Queue<T>::Is_Empty() {     //Defining the boolean function to check if the queue is empty or not
    last_error = false;
    if (Front == NULL && Back == NULL)
        return true;
    else
        return false;
}




template <typename T>
void Queue<T>::Enqueue(const T& new_val) {      //Defining the enqueue member: appends an item to the queue
    DoubleNode<T>* new_node = new DoubleNode<T>;
    new_node->set_item(new_val);
    new_node->set_next(Back);
    if (Back != NULL)
    {
        Back->set_prev(new_node);
    }
    else
    {
        Front = new_node;
    }
    Back = new_node;
    last_error = false;
}

template <typename T>
T Queue<T>::Dequeue() {      //Defining the dequeue member: deletes the item at the front
    if (Is_Empty())
    {
        last_error = true; //if the queue's empty, return error
    }
    DoubleNode<T>* dying_node = Front;
    T value = dying_node->get_item();
    //If the queue has only one element, thus Front == Back
    if (Front == Back)
    {
        delete dying_node;
        Front = NULL;
        Back = NULL;
        return value;
    }
    Front = Front->get_prev();
    Front->set_next(NULL);
    dying_node->set_prev(NULL);
    delete dying_node;
    last_error = false;
    return value;

}
#endif
