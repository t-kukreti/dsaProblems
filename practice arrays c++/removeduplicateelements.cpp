#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> v ){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int removeduplicates(vector<int> &v ){
    int s = 0 , n = v.size() , e = s+1 , key = 0;
    while(v[s] <= v[e] && e < n){
        e=s+1;

        if(v[s] == v[e] ){
            key = v[e];
            int i = e;
            while(i<n-1){
                v[i] = v[i+1];
                i++;
            }
            v[n-1] = key;
            print(v);
        }
        else{
            s++;
        }
        
    
    }
    // To find length
    for(int a = 0; a<n;a++){
        for(int b=a+1; b<n;b++){
            if(v[a] == v[b]){
                return b;
            }
        }
    }
    return 0;
    /*
    // A simple one
     int p = 0;
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[p] != nums[i]){
                nums[p+1] = nums[i];
                p++;
            }
        }
        return p + 1;
    }
    
    */
}

int main(){
    vector<int> nums = {1};
    int length = removeduplicates(nums);
    cout<<"The length is " << length <<endl;
    return 0;
}