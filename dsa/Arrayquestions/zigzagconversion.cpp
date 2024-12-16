#include<iostream>
#include<vector>
// not passing in leetcode, getting some fancy errors 
using namespace std;
bool columnFilled = false;
bool rowFilled = true;
void printVector(vector<vector<char>> v){
    for(int i = 0; i<v.size(); i++){
        for(int j = 0; j<v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void pushInVector(vector<vector<char>> &v, char element, int rows){
    static int i = -1, j = 0;
    if(!columnFilled){
        i++;
        if(i > rows - 1){
            i--;
            rowFilled = false;
            columnFilled = true;
        }
        else{
            v[i][j] = element;
        }
    }
    if(!rowFilled){
        i--, j++;                                                           
        if(i > 0){               
            v[i][j] = element;
        }
        else{
            v[i][j] = element;
            rowFilled = true;
            columnFilled = false;
        }
    }
        // a better code would be
        // v[i][j] = element;
        // if(i == 0){
        //     rowFilled = true;
        //     columnFilled = false;
}
string getString(vector<vector<char>> &v){
    string ans;
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            if(v[i][j] != '\0'){
                ans.push_back(v[i][j]);
            }
        }
    }
    return ans;
}
string convert(string s, int rows){
    vector<vector<char>> v(rows, vector<char>(s.length()));
    for(int i = 0; i < s.length(); i++){
        pushInVector(v, s[i], rows);
    }
    return getString(v);
}
int main(){

    string s = "TARUNKUSIA";
    int numRows = 3;
    cout << " before converting : " << s << endl;
    string ans = convert(s, numRows);
    cout << " after converting : " << ans << endl;
    
    return 0;
}