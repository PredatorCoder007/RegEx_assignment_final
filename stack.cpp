#include <iostream>

// THIS STRUCTURE IS JUST A GUIDELINE
// FEEL FREE TO CHANGE WHATEVER YOU WANT

class Stack{
private:
    int* s;
    int top;
    int size;
    int MAX_SIZE;

public:

    // Default Constructor
    Stack(){
        // Dynamically allocate memory for stack using keyword "new"
        // Initialize top, size
        // set MAX_SIZE to whatever you want
    }

    // Additional Constructor
    Stack(int MAX_SIZE){
        // Dynamically allocate memory for queue using keyword "new"
        // Initialize top, size

        // setting MAX_SIZE according to the parameter
        this->MAX_SIZE = MAX_SIZE;
    }

    bool push(int elem){
        // insert element at top of stack
        // check if stack is full already
        // if insertion is successfull return true
        // else return false
    }

    int pop(){
        // remove element from the top of stack
        // return the removed element
        // do not forget to change values of top, size appropriately
        // if stack is empty return -1
    }

    int get_size(){
        // return current size of stack
    }

    int get_max_size(){
        // return max size of stack
    }

};
