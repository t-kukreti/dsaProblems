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
        this-> data = data;
        this-> left_child = NULL;
        this-> right_child = NULL;
    }
};
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
// there are two ways to traverse a binary tree 
// 1. breadth first search
// 2. depth first search, different type of searches (inorder, preorder, postorder)

void preOrderSearch(Node* root){
    // in this type of search you print the root first then left child if present and then right child 
    if(root == NULL){
        return ;
    }
    cout << root-> data << " ";
    preOrderSearch(root-> left_child);
    preOrderSearch(root-> right_child);
}
void inOrderSearch(Node* root){
    if(root == NULL){
        return ;
    }
    inOrderSearch(root-> left_child);
    cout<< root-> data << " ";
    inOrderSearch(root-> right_child);
}
void postOrderSearch(Node* root){
    if(root == NULL){
        return ;
    }
    postOrderSearch(root-> left_child);
    postOrderSearch(root-> right_child);
    cout << root-> data << " ";
}

//  IMPLEMENTATION OF BFS TRAVERSAL (it is done level by level)
// storing the elements in a vector 
vector<vector<int>> levelOrder(Node* root){
    vector<vector<int>>ans;
    if(root == nullptr){
        return ans;
    }
    queue<Node*> currentLevel;
    currentLevel.push(root);
    vector<int> level;
    while(!currentLevel.empty()){
        for(int i=0; i<currentLevel.size(); i++){
            Node* temp = currentLevel.front();
            currentLevel.pop();
            if(temp->left_child != nullptr){
                currentLevel.push(temp-> left_child);
            }
            if(temp->right_child != nullptr){
                currentLevel.push(temp-> right_child);
            }
            level.push_back(temp->data);
        }
        ans.push_back(level);
        level.clear();
    }
    return ans;
}
void printVector(vector<vector<int>> v){
    for(int i = 0; i<v.size(); i++){
        for(int j = 0; j<v[i].size(); j++){
            cout << v[i][j] << " ";
        }
    }
    cout << endl;
}

// just printing elements 
void bfs(Node* root){
    queue<Node*> elementsContainer;
    elementsContainer.push(root);

    while(!elementsContainer.empty()){
        int size = elementsContainer.size();
        for(int i = 0; i < size; i++){
            Node* temp = elementsContainer.front();
            elementsContainer.pop();
            if(temp-> left_child) elementsContainer.push(temp-> left_child);
            if(temp-> right_child) elementsContainer.push(temp-> right_child);
            cout << temp-> data << " ";
        }
    }
}




int main(){
    Node* root = new Node(1);
    root-> left_child = new Node(2);
    root-> left_child-> left_child = new Node(3);
    root-> left_child-> right_child = new Node(4);
    root-> left_child-> right_child-> left_child = new Node(10);
    root-> left_child-> right_child-> left_child-> left_child = new Node(20);
    root-> left_child-> right_child-> left_child-> right_child = new Node(50);
    root-> right_child = new Node(5);
    root-> right_child-> left_child = new Node(6);
    root-> right_child-> right_child = new Node(7);
    cout << " preOrderSearch: ";
    preOrderSearch(root);
    cout << endl;
    cout << " inOrderSearch: ";
    inOrderSearch(root);
    cout << endl;
    cout << " postOrderSearch: ";
    postOrderSearch(root);
    cout << endl;
    printVector(levelOrder(root));
    cout << " bfs traversal: ";
    bfs(root);
    cout << endl;

    return 0;
}