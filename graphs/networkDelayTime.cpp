#include <algorithm>
#include <climits>
#include<iostream>
#include<vector>

using namespace std;

int networkDelayTime(vector<vector<int>> &times, int n, int k){
    vector<vector<pair<int,int>>> adjList(n+1);
    vector<int> dist(n+1, INT_MAX);
    vector<bool> visited(n+1, false);

    for(int i=0; i<times.size(); i++){
        int sourceNode = times[i][0];
        int targetNode = times[i][1];
        int timeTaken = times[i][2];

        adjList[sourceNode].push_back({targetNode, timeTaken});

    }

    dist[k] = 0; // starting from this node. 

    for (int count = 0; count < n; count ++){



        // find the smallest node 
        int smallestDistance = INT_MAX;
        int smallestNode = -1;
        for(int i = 1; i < dist.size(); i++){
            if(dist[i] < smallestDistance && !visited[i]){
                smallestDistance = dist[i];
                smallestNode = i;
            }
        }
        if(smallestNode == -1) break;
        // proces the adj list of smallest node
        for (int i = 0; i < adjList[smallestNode].size(); i++){
            int targetNode = adjList[smallestNode][i].first;
            int timeTaken = adjList[smallestNode][i].second;

            if(dist[smallestNode] + timeTaken < dist[targetNode]){
                dist[targetNode] = dist[smallestNode] + timeTaken;
            }
        }

        visited[smallestNode] = true;


    }
    int maxDistance = 0; 
    for(int i=1; i<dist.size(); i++){
        if(dist[i] == INT_MAX){
            return -1;
        }
        maxDistance = max(maxDistance, dist[i]);
    }
    return maxDistance;
}

int main(){

    vector<vector<int>> times = {
        {2,1,1},
        {2,3,1},
        {3,4,1}
    };

    cout << networkDelayTime(times, 4, 2) << endl;

    return 0;

}
