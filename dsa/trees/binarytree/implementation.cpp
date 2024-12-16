#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left_child;
    Node* right_child;

    Node(int data){
        this->data = data;
        this->left_child = NULL;
        this->right_child = NULL;
    } 
};
// recursive way to build a binary tree
Node* binaryTree(Node* root){
    cout << " Enter data ";
    int data;
    cin>> data;

    root = new Node(data);
    if(data == -1){
        return NULL;
    }
    cout << "Enter data for inserting in left of " << data << endl;
    root->left_child  = binaryTree(root->left_child);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right_child  = binaryTree(root->right_child);
    return root;
};
int main(){
    Node* root = NULL;
    root = new Node(1);
    cout << " before assigning: " << root->left_child<< endl;
    root->left_child = new Node(2);
    cout << " after assigning: " << root->left_child << endl;
    root->right_child = new Node(3);
    root->left_child->left_child = new Node(4);
    root->left_child->right_child = new Node(5);
    cout << root->data << endl;
    cout << root->left_child->data << endl;
    cout << root->right_child->data << endl;
    cout << root->left_child->left_child->data << endl;
    cout << root->left_child->right_child->data << endl;
    return 0;
}