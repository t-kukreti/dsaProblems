#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
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
    root->left  = binaryTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right  = binaryTree(root->right);
    return root;
};
void print(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
void getLeftNodes(Node* root, vector<int> &ans){
    if((root == NULL) || (root-> left == NULL && root-> right == NULL)){
        return ;
    }
    ans.push_back(root-> data);
    getLeftNodes(root-> left, ans);
}
void getLeafNodes(Node* root, vector<int> &ans){
    if(root == NULL){
        return ;
    }
    // push leaf node
    if(root-> left == NULL && root-> right == NULL){
        ans.push_back(root-> data);
        return ;
    }
    getLeafNodes(root-> left, ans);
    getLeafNodes(root-> right, ans);
}
void getRightNodes(Node* root, vector<int> &ans){
    if((root == NULL) || (root-> left == NULL && root-> right == NULL)){
        return ;
    }
    getRightNodes(root-> right, ans);
    ans.push_back(root-> data);
}
// leetcode solution 

// void getLeftNodes(Node* root, vector<int> &ans){
//     if((root == NULL) || (root-> left == NULL && root-> right == NULL)){
//         return ;
//     }
//     ans.push_back(root-> data);
//     if(root-> left){
//         getLeftNodes(root-> left, ans);
//     }
//     else{
//         getLeftNodes(root-> right, ans);
//     }
// }
// void getLeafNodes(Node* root, vector<int> &ans){
//     if(root == NULL){
//         return ;
//     }
//     // push leaf node
//     if(root-> left == NULL && root-> right == NULL){
//         ans.push_back(root-> data);
//         return ;
//     }
//     getLeafNodes(root-> left, ans);
//     getLeafNodes(root-> right, ans);
// }
// void getRightNodes(Node* root, vector<int> &ans){
//     if((root == NULL) || (root-> left == NULL && root-> right == NULL)){
//         return ;
//     }
//     if(root-> right){
//         getRightNodes(root-> right, ans);
//     }
//     else{
//         getRightNodes(root-> left, ans);
//     }
//     ans.push_back(root-> data);
// }
//     vector <int> boundary(Node *root)
//     {
//         vector<int> ans;
//         if(root == NULL){
//             return ans;
//         }
//         if(root-> left == NULL && root-> right == NULL){
//             ans.push_back(root-> data);
//             return ans;
//         }
//         if(root-> left){
//             getLeftNodes(root, ans);
//         }
//         else{
//             ans.push_back(root-> data);
//         }
//         getLeafNodes(root, ans);
//         getRightNodes(root-> right, ans);
//         return ans;
//     }
int main(){
    Node* root = binaryTree(root);
    vector<int> ans;
    getLeftNodes(root, ans);
    getLeafNodes(root, ans);
    getRightNodes(root, ans);
    print(ans);
    // 1 2 4 6 -1 -1 5 -1 -1 9 -1 3 7 -1 -1 8 -1 -1  
    return 0;
}