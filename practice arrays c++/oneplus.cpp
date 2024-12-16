#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> v){
    for(int i =0 ; i<v.size() ; i++){
        cout<< v[i] << " ";
    }
    cout<<endl;
}
  vector<int> plusOne(vector<int>& v) {
        int end = v.size() -1;
        while(end>=0){
            if(end == v.size()-1){
                v[end]++;
            }
            if(v[end]==10){
                v[end]=0;
                if(end!=0){
                    v[end-1]++;
                }
                else{
                    v.push_back(0);
                    v[end]=1;
                }
            }

            end -- ;
        }
    return v;
    }

int main(){
    vector<int> v {9,9};
     print(plusOne(v));
    return 0;
}