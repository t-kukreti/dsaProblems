#include<iostream>
#include<vector>
using namespace std;
void printarr(vector<int>& v){
    for(int i = 0;i<v.size();i++){
        cout<<char(v[i]);
    }
    cout<<endl;
}
void reverse(vector<int>& v){
    int s = 0 , e = v.size()-1;
    while(s<=e){
        swap(v[s++],v[e--]);
    }
}
vector<int> to_lower(vector<int>& v){
     vector<int> lower;
    for(int i= 0 ; i<v.size();i++){
        lower.push_back(tolower(v[i]));
    }
    cout<<"Before reverse " ;
    printarr(lower);
    cout<<endl;
     // reverse(lower); you don't need to 
      return lower;
}
bool check_palindrome(vector<int> &v){
  cout<<"Inside palindrome function  " <<endl;
  printarr(v);
  
    int s = 0 ;
    int e = v.size()-1;
    while(s<=e){
        if(v[s]!=v[e]){
            cout<<"Not palindrome "<<endl ;
            return false;
        }
        else {
            s++ , e--;
        }
    }
    cout<<"Palindrome string " <<endl;
    return true;
}

int main(){
   //vector<int> name = {'N','i','t','i','n'};
   vector<int> name = {'T' , 'A' , 'R' , 'U' ,'N'};
  printarr(name);
 vector<int> n = to_lower(name);
  cout<<"after getting lower " <<endl;
 printarr(n);
 check_palindrome(n);
  //printarr(name);
  
   
     
    

    return 0;
}