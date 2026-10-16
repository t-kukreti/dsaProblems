#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Node{
    public:
        int val;
        vector<Node*> neighbours;
        Node(){
            val = 0;
            neighbours = vector<Node*>();
        }

        Node(int _val){
            val = _val;
            neighbours = vector<Node*>();
        }
        
        Node(int _val, vector<Node*> _neighbours){
            val = _val;
            neighbours = _neighbours;
        }

};
Node* cloneAndExplore(Node* node, unordered_map<Node*, Node*> &mp){
    Node* cloneNode = nullptr;
    if(node == nullptr) return nullptr;
// check if node exists in map, return the clone of the original node
    if(mp.count(node)){
        auto it = mp.find(node);
        return it-> second;
    }else{
        // create new node, explore its neigbours and connect
        cloneNode = new Node(node-> val);
        mp.insert({node, cloneNode});
        for(int i=0; i<node-> neighbours.size(); i++){
            Node* temp = cloneAndExplore(node-> neighbours[i], mp);
            cloneNode->neighbours.push_back(temp);
        }
    }
return cloneNode;
}
Node* cloneGraph(Node* node){
    if(node == nullptr) return nullptr;

    unordered_map<Node*, Node*> mp;
    
    Node* ans = cloneAndExplore(node, mp);

    return ans;

}
int main(){
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1-> neighbours.push_back(node2);
    node1-> neighbours.push_back(node4);

    node2-> neighbours.push_back(node1);
    node2-> neighbours.push_back(node3);

    node3-> neighbours.push_back(node2);
    node3-> neighbours.push_back(node4);

    node4-> neighbours.push_back(node1);
    node4-> neighbours.push_back(node3);

    Node* res = cloneGraph(node1);

    return 0;
}
