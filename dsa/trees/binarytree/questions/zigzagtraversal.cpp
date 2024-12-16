#include<iostream>
#include<vector>
#include<queue>
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
vector<int> zigZagTraversal(Node* root){
    vector<int> result;
    if(root == NULL){
        return result;
    }

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;
    while(!q.empty()){
        int size = q.size();
        vector<int> ans(size);

        // level processing
        for(int i = 0; i < size; i++){
            Node* temp = q.front();
            q.pop();
            // normal insert or reverse insert
            int index = leftToRight ? i : size - i -1;
            ans[index] = temp-> data;

            if(temp-> left_child) q.push(temp-> left_child);
            if(temp-> right_child) q.push(temp-> right_child);
        }
        // change direction
        leftToRight = !leftToRight;

        for(auto i : ans){
            result.push_back(i);
        }
    }
    return result;
}
void print(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
int main(){
    Node* root = NULL;
    root = binaryTree(root);
    cout << "This is zigzag traversal " << endl;
    print(zigZagTraversal(root));
    return 0;
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1 
}