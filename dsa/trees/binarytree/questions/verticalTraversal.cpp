#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int data){
        this-> data = data;
        this-> left = left;
        this-> right = right;
    }

};

// preOrder traversal
void preOrder(Node* root){
    if(root == nullptr) return ;
    
    preOrder(root-> left);
    cout << root-> data << " ";
    preOrder(root-> right);
}
// vertical traversal

map<int,map<int, vector<int> > > verticalTraversal(Node* root){
    map<int, map<int, vector<int> > > nodes;
    queue<pair<Node*, pair<int,int> > > q;
    vector<int> ans;
    if(root == nullptr){
        return nodes;
    }
    q.push(make_pair(root, make_pair(0,0)));
    // fill the map
    while(!q.empty()){
        pair<Node*, pair<int,int> > temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;
        nodes[hd][level].push_back(frontNode-> data);
        if(frontNode-> left) q.push(make_pair(frontNode-> left, make_pair(hd-1, level+1)));
        if(frontNode-> right) q.push(make_pair(frontNode-> right, make_pair(hd+1, level+1)));
    }
    // traverse the map
    // for(auto i: nodes){
    //     for(auto j: i.second){
    //         for(auto k: j.second){
    //             ans.push_back(k);
    //         }
    //     }
    // }

    return nodes;

}

// traversing the vector
void printVector(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void playWithMap(Node* root){
    map<int,map<int,vector<int> > > mp = verticalTraversal(root);
    for(auto i: mp){
        for(auto j: i.second){
            for(auto k: j.second){
                cout << k << " ";
            }
        }
    }
}


int main(){
    Node* root = new Node(1);
    root-> left = new Node(2);
    root-> right = new Node(3);
    root-> left-> left = new Node(4);
    root-> left-> right = new Node(5);
    root-> right-> left = new Node(6);
    root-> right-> right = new Node(7);

    cout << " preOrder traversal: ";
    preOrder(root);
    cout << endl;
    cout << " vertical traversal: ";
    playWithMap(root);
    // printVector(verticalTraversal(root));
    cout << endl;

    return 0;
}