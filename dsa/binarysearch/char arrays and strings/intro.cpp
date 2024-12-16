#include<iostream>
#include<vector>
#include<cctype>
using namespace std;

void printarr(vector<int> &v){
    for(int i = 0 ;i < v.size();i++){
        cout<<char(v[i]);
    }
    cout<<endl;
}
void reverse1(vector<int>&v){
  int s = 0 , e = v.size()-1;
    while(s<=e){
        swap(v[s++],v[e--]);
    }
}

void reverse (char name[],int n){
    int s = 0 , e = n-1;
    while(s<=e){
        swap(name[s++],name[e--]);
    }
}
void lower_case(char name[],int n ){
  vector<int> name1;
  for(int i = 0; i<n;i++){
    name1.push_back((tolower(name[i]))); 
  }
  reverse1(name1);
 // printarr(name1);
 
}
bool checkpalindrome(char name[] , int len){

    int s = 0 , e =len -1;
   
    while(s<=e){
       if(name[s++]!=name[e--]){
        return false;
       }    
    }
return true;

}

int getlength(char name[]){
    int count = 0;
 for(int i= 0 ;name[i]!='\0' ; i++){
    count ++;
 }
 return count;
}
int main(){
    char name[20];

    cout<<"Enter your name " <<endl; // \0 (null character) gets automatically after your name ends it works as a terminator
    cin>>name;
  //  name[2] = '\0';
    cout<<"Your name is " <<name <<endl ; // cin stop executing once it gets space , tab(\t) , newline(\n)
    int len = getlength(name);
    cout<<"Length is " <<len<<endl;
    reverse(name,len);
    cout<<"Your reverse name is " <<name <<endl;
 // lower_case(name , len);
  if(checkpalindrome(name,len)){
    cout<<"Yes its a palindrome string " <<endl;
    return 1;
  }
  cout<<"No palindrome string found " <<endl;

  
    return 0;
}