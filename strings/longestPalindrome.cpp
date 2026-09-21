#include<iostream>
#include<string>

using namespace std;

pair<int,int> expandAroundCentre(string &s, int left, int right){

    while(left >= 0 && right < s.size() && s[left] == s[right]){
        left --, right ++; 
    }
    
    return {left+1, right-1};
}

string longestPalindrome(string s){
    // get a middle and expand outwards(if it keeps matching)(until out of bounds)
    // if mismatch occurs, shift the middle repeat the same thing.
    // odd string = mid => one element (left = right = 0)
    // even string = mid => two element (left = 0, right = left + 1)

    // for each centre
    int bestStart = 0, bestEnd = 0, len = 0;
    for(int centre = 0; centre < s.size(); centre++){
        // for odd palindrome
        pair<int,int> boundariesOfOddPalindrome = expandAroundCentre(s, centre, centre);
        pair<int,int> boundariesOfEvenPalindrome = expandAroundCentre(s, centre, centre+1);
        
        int lenOfOddPalindrome = boundariesOfOddPalindrome.second - boundariesOfOddPalindrome.first + 1;
        int lenOfEvenPalindrome= boundariesOfEvenPalindrome.second - boundariesOfEvenPalindrome.first + 1;

        pair<int,int> longerPalindrome = (lenOfOddPalindrome > lenOfEvenPalindrome) ? boundariesOfOddPalindrome : boundariesOfEvenPalindrome;

        int bestLen = longerPalindrome.second - longerPalindrome.first + 1;

        if(bestLen > len){
            bestStart = longerPalindrome.first;
            bestEnd = longerPalindrome.second;
            len = bestLen;
        }
    }

    return s.substr(bestStart, (bestEnd - bestStart) + 1);

}


int main(){
    string s = "babad";
    cout << longestPalindrome(s) << endl;
    return 0;   
}