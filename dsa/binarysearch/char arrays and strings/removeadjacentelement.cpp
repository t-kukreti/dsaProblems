#include<iostream>
#include<string>
using namespace std;
// code properly 

void delete_adjacent_duplicate (string &a){
    
    int low = 0;
    while(low<a.length()){
        cout<<"step " <<low<<endl;
        if(a[low]==a[low+1]){
            a.erase(low,2);
            low=0;
            
            
        }
        else{
            low++;   
        }
    
    }


}
int main(){
    string s = "abbaca"; 
    cout<<"Before deleting " <<s <<endl;
    delete_adjacent_duplicate(s);
    cout<<"After deleting " << s <<endl;

   
    return 0;
}