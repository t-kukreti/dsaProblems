#include<iostream>
using namespace std;
bool is_solution(int rank[],int n,int m,int mid){
    int dish_counter = 0;
    int time = 0;
    
    for(int i= 0 ;i<n;i++){
        
            time = rank[i];
            int j = 2;
           

            while(time<=mid){
                dish_counter ++;
               if(dish_counter>m){
                break;
               }
                time = time + (rank[i]*j) ;
                j++;
            }

        if(dish_counter >= m){
            return true;
        }
    }
    return false;

}
int minimum_time_taken_to_cook(int rank[],int n, int m){
    int mini = rank[n-1] , total_time = 0;
    for(int i =0 ;i<n;i++){
          mini = min(rank[i],mini);  
    }

    for(int i = 1;i<=m;i++){
         total_time += mini*i; 
         
    }
  int e = total_time;
  int s = 0;
  int mid = s + (e-s)/2;
  cout<<"s is " << s << " e is " << e << " mid is " << mid << endl;
  int ans = -1;
 while(s<=e){
    if(is_solution(rank,n,m,mid)){
            ans = mid;
            e= mid -1;
    }
    else{
            s= mid +1;
    }
    mid = s + (e-s)/2;
  }
 return ans;

}

int main(){
    int rank[] = {1,2,3,4};
    int n = sizeof(rank)/sizeof(rank[0]);
    int m ;
    cout<<"Enter the number of dishes you wanted to be cooked : " ;
    cin>>m ;
    cout<<endl;
    cout<<"Minimum time to cook " << m << " dishes " << " is " 
      <<minimum_time_taken_to_cook(rank,n,m);
    return 0;
}