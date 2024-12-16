#include <iostream>
#include <vector>
using namespace std;
char nextGreatestLetter(vector<char> &letters, char target)
{
    int n = letters.size()-1;
    // if last letter of letters is smaller than target then no smaller char is present in letters
    if(letters[n] <= target ){
        return letters[0];
    }

    for(int i = 0 ; i<=n ; i++){
        if(letters[i] > target){
            return letters[i];
        }
    }
    return letters[0];
}

int main()
{
    vector<char> letters = {'c','f','j'};
    char target = 'g';  
    char ans = nextGreatestLetter(letters,target);

    cout<<"Next greatest letter after " << target << " is : " << ans <<endl;

    return 0;
}