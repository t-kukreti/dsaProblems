#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool can_distribute(int n, vector<int>&quantities, int max_products){
    int filled_stores = 0;
    for(int i = 0; i < quantities.size(); i++){
        filled_stores += (quantities[i] / max_products);
        if(quantities[i] % max_products != 0){
            filled_stores++;
        }
    }
    if(filled_stores <= n){
        return true;
    }
    return false;
}

int minimizedMaximum(int n, vector<int>& quantities) {
    int left = 1, right = *max_element(quantities.begin(), quantities.end());
    int min_el = -1;
    while(left <= right){
        int mid = left + (right - left) / 2;

        if(can_distribute(n, quantities, mid)){
            min_el = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return min_el;
}

int main(){
    int n = 7;
    vector<int> quantities = {15,10,10};
    cout << minimizedMaximum(n,quantities) << endl;

    return 0;
}