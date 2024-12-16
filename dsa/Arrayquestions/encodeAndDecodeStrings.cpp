#include<iostream>
#include<string>
#include<vector>
using namespace std;

void printVector(vector<string> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

string encode(vector<string> &strs){
    string encodedString = "";
    for(int i = 0; i < strs.size(); i++){
        encodedString += to_string(strs[i].size()) + "#" + strs[i];
    }
    return encodedString;
}
string getString (string str, int s, int e){
    string ans = "";
    for(int i = s; i <= e; i++){
        ans += str[i];
    }
    return ans;
}
vector<string> decode(string s){
    vector<string> decodedVector;
    int n = s.size();
    string st = "";
    string ans = "";
    int i = 0;
    int len = 0;
    int offset = 0;
    while( i < n){
        
        while(s[i] != '#' && i < n){
            st += s[i];
            i++;
        }
        len = stoi(st);
        offset = len + i;
        ans = getString(s, (i+1), offset);
        decodedVector.push_back(ans);
        ans.clear();
        st.clear();
        i = offset + 1;
    }
    return decodedVector;
}


int main(){
    vector<string> strs = {"we","say",":","yes","!@#$%^&*()"};
    string encodedString = encode(strs);
    cout << encodedString << endl;
    vector<string> decodedVector = decode(encodedString);
    printVector(decodedVector);
    return 0;
}