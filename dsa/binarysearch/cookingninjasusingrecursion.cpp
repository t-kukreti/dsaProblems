#include<iostream>
using namespace std;
// When ninjas are not working simultaneously , if they are then this answer is wrong
bool ispos(int *time , int mid,int dishes,int n){
  int dish_counter = 0;
    int total = 0;
    for(int i= 0 ;i<n;i++){
          int  timetaken = time[i];
          total = timetaken + total;
            int R = 2;
            while(total<=mid){
                dish_counter ++;
                total = total + (time[i]*R) ;
                R++;
            }
            if(total>mid && dish_counter<dishes){
                total = total - (time[i]*--R);
            }

        if(dish_counter >= dishes){
            return true;
        }
    }
    return false;
    
}

int minimum_time_to_cook(int *time,int s,int e,int dishes,int ans,int n){
    if(s>e){
        return ans;
    }
    int mid = s +(e-s)/2;
    cout<<"s is " << s << " and e is " << e << " mid is "  << mid << endl;
    if(ispos(time,mid,dishes,n)){
        ans = mid;
        cout<<"ans is " << mid<< endl;
        return minimum_time_to_cook(time,s,mid-1,dishes,ans,n);
    }
    else{
        return minimum_time_to_cook(time,mid+1,e,dishes,ans,n);
    }

}

int main(){
    int time[]={1,2,3,4};
    int dishes;
    cout<<"Enter number of dishes ";
    cin>>dishes;
    int n = sizeof(time)/sizeof(time[0]);
    int ans = -1;
    int maxtime=0;
    for(int i = 1 ; i<=dishes ; i++){
        maxtime += i*time[0];
    }
    int sol =  minimum_time_to_cook(time,0, maxtime ,dishes, ans,n);
    cout<<"Minimum time is " << sol << " min " << endl;

    
    return 0;
}