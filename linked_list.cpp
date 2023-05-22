#include<iostream>
using namespace std;

// for implementing given exercise we would implement doubly linked list

struct Node{
   int data;
   Node* prev;
   Node* next;

};

class doubly_linked_list{
private:
    Node* head;
    Node* tail;

public:
    doubly_linked_list() : head(nullptr),tail(nullptr){}

   void insert_front(int value){
        Node* new_Node = new Node;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = head;

        if(head != nullptr){
            head->prev = new_Node;
        }

        head = new_Node;

        if(tail == nullptr){
            tail = head;
        }
    }

    void insert_end(int value){
        if(tail == nullptr){
            insert_front(value);
            return;
        }

        Node* new_Node = new Node;
        newNode->data = value;
        newNode->prev = tail;
        newNode->next = nullptr;

        tail->next = new_Node;
        tail = new_Node;

    }

    void delete_front(){
        if(head == nullptr){
            return; // list is empty
        }

        Node* node_to_delete = head;

        if(head == tail){
            //one node in linked list
            head = nullptr;
            tail = nullptr;
        }

        else{
            head = head->next;
            head->prev = nullptr;
        }

        delete node_to_delete;
    }

    void delete_back(){
        if(tail == nullptr){
            return; // list empty
        }

        Node* node_to_delete = tail;

        if(head == tail){
            //only one mode in the list
            head = nullptr;
            tail = nullptr;
        }

        else{
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete node_to_delete;
    }

};

