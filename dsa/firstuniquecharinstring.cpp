#include<iostream>
#include<map>
using namespace std;
int firstUniqChar(string s){
    if(s.length() == 1){
        return 0;
    }
    map<char, int> mp;
    for(int i = 0; i < s.length(); i++){
        mp[s[i]]++;
    }

    for (int i = 0; i < s.length(); i++) {
        if (mp[s[i]] == 1) {
            return i;
        }
    }

return -1;
}
int main() {
string s = "a";
int ans = firstUniqChar(s);
cout << " ans is " << ans << " which is " << s[ans] << endl;
    return 0;
}