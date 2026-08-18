#include<iostream>
#include<string>
using namespace std;

int starting_index_of_matching_pattern(string &s, string &part){
    for(int i=0; i<s.length() - part.length(); i++){
        // if first char matches of both string and part 
        if(s[i] == part[0]){
            int k = i+1, cnt = 1;
            // now check for the substring 
            for(int j=1; j<part.length(); j++){
                if(part[j] == s[k]){
                    k++; cnt++;
                }
                else{
                    cnt = 0;
                    break;
                }
            }
            if(cnt == part.length()) return i;
        }
    }
    return -1;
}

string removeOccurences(string s, string part){
    int pos = starting_index_of_matching_pattern(s,part);
    while(pos != -1){
        s.erase(pos,part.length());
        pos = starting_index_of_matching_pattern(s,part);
    }
    return s;
}
// optimal solution 
/*
string removeOccurences(string s, string part){
    size_t pos;
    while( (pos = s.find(part)) != string::npos){
        s.erase(pos,part.length());
    }
    return s;
}
*/

int main(){
    string s = "axyxyxyxyb";
    string part = "xy";
    cout << removeOccurences(s,part) << endl;

    return 0;
}
