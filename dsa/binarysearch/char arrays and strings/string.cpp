#include<iostream>
using namespace std;

char getmaxoccuringcharacter(string s){
    int arr[26]={0};
    for(int i = 0 ; i<s.length();i++){
        char ch = s[i] ;
        // lowercase 
        int number = 0 ;
        if(ch>='a' && ch<='z'  ){
             number = ch - 'a';
        }
        // uppercase
        else {
            number = ch - 'A'; 
        }
            arr[number]++;
    }
        int maxi = -1;
         int ans = 0;
        for(int i = 0; i<26;i++){
            if(maxi<arr[i]){
                ans = i;
                maxi = arr[i];
            }
                
        }

    char finalans = 'a' + ans;
         return finalans;

}
int main(){
    string s;
    cout<<"Enter your string " <<endl;
    cin>>s;
    cout<<"The maximum occuring element in the string is " <<getmaxoccuringcharacter(s);
    return 0;
}