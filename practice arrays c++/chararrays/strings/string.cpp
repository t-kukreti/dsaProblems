#include<iostream>
#include<string>
using namespace std;
char to_lowercase(char ch){
    if(ch>='a' && ch <= 'z'){
        return ch;
    }
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}
bool check_palindrome(string name){
    int s = 0 , e = name.size()-1;
        while(s<=e){
            if(to_lowercase(name[s])!= to_lowercase(name[e])){
                cout<<"Not palindrome " <<endl;
                break;
                return 0;
            }
            else { // s==e
                s ++;
                e--;
            }
        }
       
        return true;
}

int main(){
    string name;
    cout<<"Enter your name " ;
    getline(cin,name);
    cout<<name<<endl;
    cout<<"Length of the string is " << name.size()<<endl;
  if(check_palindrome(name)){
    cout<<"The string is palindrome " <<endl;
  }
  /*  char name[20];
    cout<<"Enter your name ";
    cin>>name;
    cout<<to_lowercase('B')<<endl ;
    cout<<to_lowercase('b')<<endl ;*/


    
    return 0;
}