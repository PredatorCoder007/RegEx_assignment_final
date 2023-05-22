// C++ code to implement the approach

#include<iostream>
#include<vector>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;
};

Node* create(int item)
{
    Node* node = new Node;
    node->data = item;
    node->left = node->right = NULL;
    return node;
}

//insert an element
Node* insertion(Node* root, int item)
{
    if(root == NULL)
        return create(item);
    if(item < root->data)
        root->left = insertion(root->left, item);
    else
        root->right = insertion(root->right, item);
    return root;

}

//find an element
void _find(Node* &cur, int item, Node* &parent)
{
    while(cur!=NULL && cur->data != item)
    {
        parent = cur;
        if(item < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

//inorder traversal
void inorder_tr(Node* root)
{
    if(root == NULL)
        return;
    //traverse left subtree
    inorder_tr(root->left);
    //traverse root node
    cout<<root->data<<" ";
    //traverse right subtree
    inorder_tr(root->right);
}


//inorder traversal vector
void inorder_tr_vec(Node* root, vector<int>& sorted_vec)
{
    if(root == nullptr){
        return;
    }

    inorder_tr_vec(root->left, sorted_vec);
    sorted_vec.push_back(root->data);
    inorder_tr_vec(root->right, sorted_vec);


}
//sort a vector using BST
vector<int> sort_vector(const vector<int>& input_vec)
{
   Node* root = nullptr;

   //construct BST
   for(int num : input_vec){
    root = insertion(root, num);
    }

   //perform inorder traversal
   vector<int> sorted_vec;
   inorder_tr_vec(root, sorted_vec);

   return sorted_vec;
}
