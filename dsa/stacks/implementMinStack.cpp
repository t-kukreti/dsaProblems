#include<iostream>
#include<vector>
using namespace std;

class MinStack{
    vector<int> st;
    vector<int> minElements;
    public:
        MinStack(){}

        void push(int value){

            st.push_back(value);
            if(minElements.size() == 0){
                minElements.push_back(value);
            }
            else{
                if(value < minElements.back()){
                    minElements.push_back(value);
                }
                else{
                    minElements.push_back(minElements.back());
                }
            }
        }
        void pop(){
            if(st.empty()){
                return ;
            }
            st.pop_back();
            minElements.pop_back();
        }
        int top(){
            if(st.empty()){
                return -1;
            }
            return st.back();
        }
        int getMin(){
            if(st.empty()){
                return -1;
            }
            return minElements.back();
        }


    
};
int main(){

    return 0;
}
