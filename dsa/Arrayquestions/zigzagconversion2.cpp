#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
void printString(string s){
    for(int i=0; i<s.size(); i++){
        cout << s[i] << " ";
    }
    cout << endl;
}
void printVector(vector<string>v){
    for(int i=0; i<v.size(); i++){
        printString(v[i]);
    }
}

vector<string> getRows(string s, int n){
        // when string size is smaller than we don't need to intialize empty rows.
    vector<string> rows(min(n, int(s.size())));
    int curRow = 0;
    bool goingDown = false;

    for(int i=0; i<s.size(); i++){
        char c = s[i];

        rows[curRow].push_back(c);
        // when curRow reaches top or bottom change direction.
        if(curRow == 0 || curRow == n - 1) goingDown = !goingDown;
        // condition ? value if true : val if false
        curRow += (goingDown) ? 1 : -1;
    }
    return rows;
}

string convert(string s, int numRows){
    vector<string> rows = getRows(s,numRows);
    // printVector(rows);
    string ans = "";
    for(int i=0; i<rows.size(); i++){
        for(int j=0; j<rows[i].size(); j++){
            ans.push_back(rows[i][j]);
        }
    }
    return ans;
}




int main(){
    string str = "TARUNSIAANKU";
    int numRows = 4;
   string ans = convert(str,numRows);
   printString(ans);

    return 0;
}