#include<iostream>
#include<stack>
using namespace std;
// Test cases are pending (codingninjas).

// naive approach
/*
1. size of array is n, lets suppose you need k stacks so divide entireLength/numberOfStacks.
2. allocate the partition .

Drawback -> space is not optimised properly.

don't use this
*/

    // APPROACH 2 :-
    /*
        1.

        top[] -> represent index of top element.
        next[] -> does two things 
        i) point to next element after stack top
        ii) point to next free space
         
    */


class NStack{
    public:
    int *arr;
    int *top;
    int *next;

    int n, s, freeSpot;


    NStack(int N, int S){
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // intialize top 
        for(int i = 0 ; i<n; i++){
            top[i] = -1;
        }
        // you can also use memset to do above thing.

        // initialize next 
        for(int i = 0 ; i<s ; i++){
            next[i] = i+1;
        }
        // update last index to -1
        next[s-1] = -1;

        freeSpot = 0;

    }
    bool push(int x, int m){
        // check for overflow
        if(freeSpot == -1){
            return false;
        }
        // find index
        int index = freeSpot;
        // update freeSpot
        freeSpot = next[index];
        // insert element
        arr[index] = x;
        // update next 
        next[index] = top[m-1];
        // update top
        top[m-1] = index;

        return true;
    }
    int pop(int m){
        // check underflow
        if(top[m-1] == -1){
            return false;
        }
        // push ka ulta hai bs 
        int index = top[m-1];
        top[m-1] = next[index];
        next[index] = freeSpot;
        freeSpot = index;
        return arr[index];
    }

};                                                                                                                                                                                                                                                      

int main(){
    
    return 0;
}