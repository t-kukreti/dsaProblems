 #include<iostream>
 #include<vector>
 using namespace std;
 
   int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        int mid = s + (e-s)/2;

        while(s<=e){
            if(nums[mid] == target){
                return mid;
            }

             if(nums[s]<=nums[mid]){
                cout<<"inside if function" <<endl;
                if(target>=nums[s] && target <= nums[mid]){
                    e = mid -1;
                }
                else{
                    s=mid +1;
                    cout<<"s is " <<s <<endl;
                }
             }

                else{
                    cout<<"inside else function" <<endl;
                    if(nums[mid]<=target && target <= nums[e]){
                        cout<<"s is inside else if " <<s <<endl;
                        s = mid;
                    }
                    else{
                        e = mid -1;
                    }
                }

            
            mid = s + (e-s)/2;  
        }
        return -1;
    }
    int main(){
        vector<int> nums = {5,1,3};
        int target = 3;
      cout<<  search(nums , target);
    }