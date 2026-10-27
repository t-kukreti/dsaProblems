#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> getList(int numCourses, vector<vector<int>> &prerequisites){
    vector<vector<int>> list(numCourses);
    for(int i = 0; i < prerequisites.size(); i++){
           int course = prerequisites[i][0];
           int prerequisite = prerequisites[i][1];

           list[prerequisite].push_back(course);

    }
    return list;
}

bool explore(vector<vector<int>> &list, vector<int> &state, int course){
    if(state[course] == 1) return false;

    if(state[course] == 2) return true;

    state[course] = 1;

    for(int i = 0; i < list[course].size(); i++){
        int neighbour = list[course][i];

        if(!explore(list, state, neighbour)) return false;

    }

    state[course] = 2;
    return true;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites){
    vector<int> state(numCourses,0);
    vector<vector<int>> adjList = getList(numCourses, prerequisites);

    for(int course = 0; course < numCourses; course++){
        if(state[course] == 0){
            if(! explore(adjList, state, course)) return false;
        }

    }
    
    return true;
}


int main(){


    vector<vector<int>> prerequisites = {
        {1,0}
    };

    cout << canFinish(2, prerequisites);

    return 0;
}
