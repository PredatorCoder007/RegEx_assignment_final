#include <iostream>
using namespace std;

// THIS STRUCTURE IS JUST A GUIDELINE
// FEEL FREE TO CHANGE WHATEVER YOU WANT

class Stack{
private:
    int* _stack;
    int  _top;
    int  _size;
    int MAX_SIZE;

public:

    // Default Constructor
    Stack(){
        // Dynamically allocate memory for stack using keyword "new"
        _stack = new int[MAX_SIZE];
        // Initialize top, size
        _top = -1;
        _size = 0;
        // set MAX_SIZE to whatever you want
        MAX_SIZE = 999999;
    }

    // Additional Constructor
    Stack(int MAX_SIZE){
        // Dynamically allocate memory for queue using keyword "new"
        _stack = new int[MAX_SIZE];
        // Initialize top, size
        _top = -1;
        _size = 0;

        // setting MAX_SIZE according to the parameter
        this->MAX_SIZE = MAX_SIZE;
    }

    bool push(int elem){
        // insert element at top of stack
        // check if stack is full already
        // if insertion is successfull return true
        // else return false
        if(_top >= MAX_SIZE - 1){
            cout<<"Stack full already\n";
            return false;
        }

        _top = _top+1;
        _stack[_top] = elem;;
        _size++;
        return true;

    }

    int pop(){
        // remove element from the top of stack
        // return the removed element
        // do not forget to change values of top, size appropriately
        // if stack is empty return -1
        if(_top<0)
        {
            return -1;
        }
        int elem = _stack[_top];
        _top = _top-1;
        _size--;
        return elem;

    }

    int get_size(){
        // return current size of stack
        return _size;
    }

    int get_max_size(){
        // return max size of stack
        return MAX_SIZE;
    }

};
