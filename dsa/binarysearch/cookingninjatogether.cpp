#include<iostream>
using namespace std;

bool ispos(int *rank , int mintime,int dishes,int n){ 
    // This function is valid if ninjas can cook simultaneously 
    // if they are not then make a totaltime which adds up time and then checks(totaltime<=mintime);
    int time = 0 , dish_count =0 ;
    for(int i =0 ; i<n ;i++){
         time = rank[i];
        int R = 2;

        while(time<=mintime){
            dish_count ++;
            time = time + (rank[i] *R );
            R++;
        }
        if(dish_count>=dishes){
            return true;
        }
    }
    return false;
}

int minimum_rank_to_cook(int *rank,int s,int e,int dishes,int ans,int n){
    if(s>e){
        return ans;
    }
    int mintime = s +(e-s)/2;
 
    if(ispos(rank,mintime,dishes,n)){
        ans = mintime;
        return minimum_rank_to_cook(rank,s,mintime-1,dishes,ans,n);
    }
    else{
        return minimum_rank_to_cook(rank,mintime+1,e,dishes,ans,n);
    }

}

int main(){
    int rank[]={1,2,3,4};
    int dishes;
    cout<<"Enter number of dishes ";
    cin>>dishes;
    int n = sizeof(rank)/sizeof(rank[0]);
    int ans = -1;
    int maxtime = (dishes*(dishes+1))/2 * rank[0]; // sum of n terms = n*(n+1)/2 * firstelement of series
    // or we can use :-
    // for(int i = 1 ; i<=dishes ; i++){
    //     maxtime += i*rank[0];
    // }
    int sol =  minimum_rank_to_cook(rank,0, maxtime ,dishes, ans,n);
    cout<<"Minimum time taken to prepare " << dishes <<" dishes by " << n  <<" cooks  is " << sol << " min " << endl;

    
    return 0;
}