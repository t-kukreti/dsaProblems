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

int height(Node* root){
    // base case
    if(root == nullptr){
        return 0;
    }
    // get the height of left subtree 
    int leftHeight = height(root-> left_child);
    // get the height of right subtree 
    int rightHeight = height(root-> right_child);
    
    int ans = max(leftHeight, rightHeight) + 1;
    return ans;
}
// this is taking too much time
int diameter(Node* root){
    if(root == nullptr){
        return 0;
    }
    int leftDia = diameter(root-> left_child);
    int rightDia = diameter(root-> right_child);
    int heightOfNode = height(root-> left_child) + height(root-> right_child) + 1;
    int ans = max(heightOfNode, max(leftDia,rightDia));
    return ans;
}
// this is much optimised
pair<int,int> fastDiameter(Node* root){
    if(root == nullptr){
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    pair<int,int> leftDia = fastDiameter(root-> left_child);
    pair<int,int> rightDia = fastDiameter(root-> right_child);
    int op1 = leftDia.first;
    int op2 = rightDia.first;
    int op3 = leftDia.second + rightDia.second + 1;

    pair<int,int> ans;
    ans.first = max(op1, max(op2,op3));
    ans.second = max(leftDia.second, rightDia.second) + 1;
    return ans;
}
int main(){
    Node* root = nullptr;
    root = binaryTree(root);
    cout << "diameter of binary tree is: " << fastDiameter(root).first << endl;
    return 0;
}