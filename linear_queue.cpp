#include <iostream>
using namespace std;
// THIS STRUCTURE IS JUST A GUIDELINE
// FEEL FREE TO CHANGE WHATEVER YOU WANT

class LinearQueue{
private:
    int* _queue;
    int  _start;
    int  _end;
    int  _size;
    int MAX_SIZE;

public:

    // Default Constructor
    LinearQueue(){
        // Dynamically allocate memory for queue using keyword "new"
        _queue = new int[MAX_SIZE];
        // Initialize start, end, size
        _start = -1;
        _end = 0;
        _size = 0;
        // set MAX_SIZE to whatever you want
        MAX_SIZE = 999999;
    }

    // Additional Constructor
    LinearQueue(int MAX_SIZE){
        // Dynamically allocate memory for queue using keyword "new"
        // Initialize start, end, size
        _queue = new int[MAX_SIZE];
        _start = -1;
        _end = 0;
        _size = 0;
        // setting MAX_SIZE according to the parameter
        this->MAX_SIZE = MAX_SIZE;
    }

    bool insert(int elem){
        // insert element at end of queue
        // check if queue is full already
        // if insertion is successfull return true
        // else return false
        if(_size == MAX_SIZE)
        {
            cout<<"Queue already full\n";
            return false;
        }

        _queue[_end] = elem;
        _size++;

        return true;
    }

    int remove(){
        // remove element from the start of queue
        // return the removed element
        // do not forget to change values of start, end, size appropriately
        // if queue is empty return -1
        if(_size == 0)
        {
            return -1;
        }

        int elem = _queue[_start];

        _start++;
        _size--;

        if(_size == 0)
        {
            _start = -1;
            _end = 0;
        }

        return elem;
    }

    int get_size(){
        // return current size of queue
        return _size;
    }

    int get_max_size(){
        // return max size of queue
        return MAX_SIZE;
    }

};
