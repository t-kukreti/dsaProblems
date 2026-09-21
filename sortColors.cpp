#include<iostream>
#include<vector>

using namespace std;


void printVector(vector<int> &v){
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
cout << endl;
}

void sortColors(vector<int> &nums) {

	int freq[3] = {};

	// get the frequency count 	
	for(int i=0; i<nums.size(); i++){
		freq[nums[i]] ++;
	}

	// in each iteration, write nums in place based on the count frequency of elements.
	int index = 0;
	for(int i=0; i<3; i++){
		for(int j=0; j<freq[i]; j++){
			nums[index] = i;
			index ++;
		}
	}

}

// another approach [Dutch nation flag] a three way partioning algo also used in 3 way partioning quicksort.
void sortColors1(vector<int> &nums){
	int low = 0, mid = 0, high = nums.size() - 1;

	while(mid <= high){
		if(nums[mid] == 0){
			swap(nums[mid], nums[low]);
			low++, mid ++;
		}
		else if(nums[mid] == 1){
			mid ++;
		}
		else if(nums[mid] == 2){
			swap(nums[mid], nums[high]);
			high --; // dont increment mid, cause the element swapped from high into mid is unknown.
		}
	}
}

int main(){
	vector<int> nums = {2,0,2,1,1,0};
	cout << "before sorting: ";
	printVector(nums);
	sortColors1(nums);
	// sortColors(nums);
	cout << "after sorting: ";
	printVector(nums);
	return 0;
}
