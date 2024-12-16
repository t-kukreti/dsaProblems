#include <iostream>
#include <algorithm>
using namespace std;

int lengthofstring(string s){
    int n = s.size();
    int len = 1;
    int start = 0 ;
    int end = start;
    int maxlen=0;
    while(start < n && end < n ){
        maxlen = max(len,maxlen);
        if(s[start] == s[end+1]){
            start ++ , end ++ ;
        }
        else{
            end ++ ;
            len = end - start + 1;
            for(int i = start ; i <= end ; i++){
                for(int j = i + 1; j<=end ; j++){
                    if(s[i]==s[j]){
                        start ++;
                        end = start +1;
                        len = 1;
                    }
                }
            }
        }
    }
    return maxlen;
}
int main()
{
    string s = "pwwkew";
    cout << "Length of longest substring  " << lengthofstring(s) << endl;
    return 0;
}