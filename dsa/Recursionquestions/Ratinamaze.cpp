#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print(vector<string>s){
    for(int i = 0 ; i < s.size() ; i++){
        cout<<s[i]<< " ";
    }
    cout<<endl;
}
bool issafe(vector<vector<int>> &m , int n , int x , int y ){
    if((x>=0 && x<n) && (y>=0 && y<n) && m[x][y] == 1){
        return true;
    }
    else{
        return false;
    }
}
void solve(vector<vector<int>> &m , int n , string path , int x , int y , vector<string>&ans){
    // basecase last position
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }
    // down
    int newx = x+1 , newy = y;
    if(issafe(m,n,newx,newy)){
        m[x][y]=0;
        path.push_back('D');
        solve(m,n,path,newx,newy,ans);
        path.pop_back();
    }
    // right
     newx = x , newy = y+1;
    if(issafe(m,n,newx,newy)){
        m[x][y]=0;
        path.push_back('R');
        solve(m,n,path,newx,newy,ans);
        path.pop_back();
    }
    // left
     newx = x , newy = y-1;
    if(issafe(m,n,newx,newy)){
        m[x][y]=0;
        path.push_back('L');
        solve(m,n,path,newx,newy,ans);
        path.pop_back();
    }
    // up
     newx = x-1 , newy = y;
    if(issafe(m,n,newx,newy)){
        m[x][y]=0;
        path.push_back('U');
        solve(m,n,path,newx,newy,ans);
        path.pop_back();
    }

    m[x][y]=1;

}
vector<string> possiblepaths(vector<vector<int>> &m , int n ){
    vector<string>ans;
    string path = "";
    int srcx = 0 ;
    int srcy = 0;
    solve(m,n,path,srcx,srcy,ans);
    sort(ans.begin(),ans.end());
    return ans;


}
int main(){
    vector<vector<int>> m = {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,1},
        {0,1,1,1}
    };
    int n = 4;
    print(possiblepaths(m,n));
    

    return 0;
}