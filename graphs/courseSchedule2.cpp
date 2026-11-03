#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> getList(int numCourses, vector<vector<int>> &prerequisites){
    vector<vector<int>> adj(numCourses);

    for(int i = 0; i < prerequisites.size(); i++){
        int course = prerequisites[i][0];
        int prerequisite = prerequisites[i][1];

        adj[prerequisite].push_back(course);
    }
    return adj;
}

bool explore(vector<int> &ans, vector<vector<int>> &adjList, vector<int> &state, int course){
    if(state[course] == 1) return false;
    if(state[course] == 2) return true;

    state[course] = 1;

    for(int i = 0; i < adjList[course].size(); i++){
        int neighbour = adjList[course][i];
        if(! explore(ans, adjList, state, neighbour)) return false;
    }

    state[course] = 2;
    ans.push_back(course);
    return true;


}



vector<int>findOrder(int numCourses, vector<vector<int>> &prerequisites){
    vector<int> ans;
    vector<vector<int>> adjList = getList(numCourses, prerequisites);
    vector<int> state(numCourses, 0);

    for(int course = 0; course < numCourses; course ++){
        if(state[course] == 0){
            if(! explore(ans, adjList, state, course)){
                ans.clear();
                return ans;
            }
            
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;

}

void printVector(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
    }
    cout << endl;
}





int main(){

    vector<vector<int>> prerequisites = {
        {1,0},
        {2,0},
        {3,1},
        {3,2}
    };

    vector<int> res = findOrder(4, prerequisites);
    printVector(res);

    return 0;
}
