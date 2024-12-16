#include<iostream>
#include<stack>
using namespace std;

int findMinimumCost(string str){
    int numof_openBrackets = 0 , numof_closedBrackets = 0 , ans = 0;
    int len = str.length();
    // if length is odd , not possible to make it valid string
    if(len & 1){
        return -1;
    }
    else{
        // even
        // make a stack , keep only invalid expression inside , remove all valid ones 
        stack<char> st;
        for(int i = 0 ; i<len ; i++){
            char ch = str[i];

            if(ch == '{'){
                st.push(ch);
            }
            else{
                if(ch == '}' && (st.empty() || st.top() == '}')){
                    st.push(ch);
                }
                else if(ch == '}' && st.top() == '{'){
                    st.pop();
                }
            }

        }
        // now stack have only invalid expression
        while(!st.empty()){
            if(st.top() == '{'){
                numof_openBrackets++;
            }
            else{
                numof_closedBrackets++;
            }
            st.pop();
        }
        ans = ((numof_openBrackets + 1)/2) + ((numof_closedBrackets + 1)/2);

    }
    return ans;
}
int main(){
    
    string str = "}}}{{{";
   int ans = findMinimumCost(str);
   cout<<"Minimum cost to make a string valid " << ans << endl;
    cout<<endl;
    
    return 0;
}