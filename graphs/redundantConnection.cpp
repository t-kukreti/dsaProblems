#include<iostream>
#include<vector>

using namespace std;

class Solution {
    
    vector<int> parent;

    int find(int node){
        // base condition
        if(parent[node] == node) return node;
        
        return find(parent[node]);
    }

    void merge(int nodeA, int nodeB){
        int rootA = find(nodeA);
        int rootB = find(nodeB);

        // if different roots then connect the nodes 
        if(rootA != rootB) parent[rootB] = rootA;

    }

    public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges){
        vector<int> ans;
        // initialize the parent 
        parent.resize(edges.size() + 1);

        for(int i = 1; i <= edges.size(); i++){
            parent[i] = i;
        }

        for(int edge = 0; edge < edges.size(); edge++){
            int nodeA = edges[edge][0];
            int nodeB = edges[edge][1];

            int rootA = find(nodeA);
            int rootB = find(nodeB);

            if(rootA == rootB){
                ans.push_back(nodeA);
                ans.push_back(nodeB);
            }else{
                merge(nodeA, nodeB);
            }

        }
        return ans;
    }

};

void printVector(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
    }
    cout << endl;
}

int main(){

    vector<vector<int>> edges = {
        {1,2},
        {2,3},
        {3,4},
        {1,4},
        {1,5}
    };
    
    Solution sol;

    vector<int> res = sol.findRedundantConnection(edges);
    printVector(res);

    return 0;
}
