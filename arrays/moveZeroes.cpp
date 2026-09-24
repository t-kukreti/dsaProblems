#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void printVector(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void moveZeroes(vector<int> &nums){
    int i = 0;

    while(i < nums.size()){

        if(nums[i] == 0){
            // we got zero
            if(i + 1 > nums.size()) break;

            int itr = i + 1; // index pointing to next of element of zero
            while(itr < nums.size()){

                if(nums[itr] != 0){
                    // any number other than 0
                    swap(nums[i], nums[itr]);
                    break;
                }

                itr ++;
            }
            if(itr == nums.size()) break;
        }

        i++;
    }
}

int main(){

    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);

    printVector(nums);

    return 0;
}