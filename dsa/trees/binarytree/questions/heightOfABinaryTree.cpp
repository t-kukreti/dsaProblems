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
int heightOfABinaryTree(Node* root){
    // base case
    if(root == nullptr){
        return 0;
    }
    // get the height of left subtree 
    int leftHeight = heightOfABinaryTree(root-> left_child);
    // get the height of right subtree 
    int rightHeight = heightOfABinaryTree(root-> right_child);
    
    int ans = max(leftHeight, rightHeight) + 1;
    return ans;
}
int diameter(Node* root){
    if(root == nullptr){
        return 0;
    }
    int op3 = heightOfABinaryTree(root-> left_child) + heightOfABinaryTree(root-> right_child) + 1;
    return op3;
}
int main(){
    Node* root = NULL;
    root = binaryTree(root);
    cout << "height of binary tree or max depth is: " << heightOfABinaryTree(root) << endl;
    cout << "diameter of binary tree is: " << diameter(root) << endl;
    return 0;
}