#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

// merge sorted list
Node* merge_sorted_list(Node* head_1, Node* head_2) // 2 heads corresponding to 2 linked list
    {
        // check for empty or not
        if(head_1 == nullptr)
            return head_2;
        if(head_2 == nullptr)
            return head_1;

        // create a merged list
        Node* merge_head = nullptr;
        Node* current = nullptr; // discuss this

        // start merge sort
        if(head_1->data <= head_2->data){
            merge_head = head_1;
            head_1 = head_1->next;
        }
        else{
            merge_head = head_2;
            head_2 = head_2->next;
        }

        current = merge_head;

        while(head_1 != nullptr && head_2 != nullptr){
            if(head_1->data <= head_2->data){
                current->next = head_1;
                head_1 = head_1->next;
            }
            else{
                current->next = head_2;
                head_2 = head_2->next;
            }

            current = current->next;
        }

        if(head_1 != nullptr)
            current->next = head_1;
        if(head_2 != nullptr)
            current->next = head_2;

        return merge_head;
    }

// insert after element

void insert_after_element(Node* head, int target_value, int insert_value){
    Node* current = head;

    while(current != nullptr){
        if(current->data == target_value){
            Node* new_node =  new Node;
            new_node->data = insert_value;
            new_node->next = current->next;
            current->next = new_node;
            return;
        }

        current = current->next;
    }

    return;
}

//find element after start and return its position
int find_element_after_pos(Node* head, int start_pos, int target_val){
    Node* current = head;
    int current_pos = 0;

    while(current != nullptr){
        if(current_pos >= start_pos && current->data == target_val){
            return current_pos;
        }

        current = current->next;
        current_pos++;
    }

    return -1;// element not found

}

