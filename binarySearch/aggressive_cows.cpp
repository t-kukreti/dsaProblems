#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool can_fit_cows(vector<int> &stalls, int min_d, int c){
    int last_placed = stalls[0];
    int count = 1;
    for(int i = 1; i < stalls.size(); i++){
        if(stalls[i] - last_placed >= min_d){
            last_placed = stalls[i];
            count ++;

            if(count >= c) return true;
        }
    }
    return false;
}

int largest_min_distance_to_fit_n_cows(vector<int> stalls, int c){
    // sort the stalls array
    sort(stalls.begin(), stalls.end());
    int min_d = 0, left = 1, right = stalls[stalls.size()-1] - stalls[0]; 
    while(left <= right){
        int mid = left + (right - left) / 2;

        if(can_fit_cows(stalls, mid, c)){
            min_d = mid;
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }

    return min_d;
}
int main(){

    vector<int> stalls = {1,2,4,8,9};
    int c = 3;

    cout << largest_min_distance_to_fit_n_cows(stalls, c) << endl;

    return 0;

}