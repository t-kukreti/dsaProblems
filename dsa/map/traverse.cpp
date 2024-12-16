#include<iostream>
#include<map>
using namespace std;
void printMap(map<int, string, greater<int>> mp){
    for(map<int, string> :: iterator it = mp.begin(); it != mp.end(); it++){
        cout << it->first << " " << it->second << endl;
    }

}
void printMap2(map<int, string> mp){
    // for(auto it = mp.end(); it != mp.begin(); it--){
    //     cout << it -> first << " " << it->second << endl;
    // }
    // this is a deadly sin mp.end() is pointing to one past the last element if you dereferce it oh boy!

    for(auto it = mp.rbegin(); it != mp.rend(); it ++){
        cout << it->first << " " << it->second << endl;
    }
}
int main(){
    map<int, string , greater<int>> mp = {
        {1, "I"},
        {5, "V"}
    };
    map<int, string> mp2 = {
        {1, "I"},
        {5, "V"}
    };
    printMap(mp);
    printMap2(mp2);

    return 0;
}