#include<iostream>
using namespace std;

string reverseWords(string s){
    int i = s.length()-1, end = -1, start = -1;
    string output = "";

    while(i >= 0 ){
        // skip spaces 
        while(i >= 0 && s[i] == ' '){
            i --;
        }
        // if there is no letter after skipping spaces
        if(i < 0){
            break;
        }

        end = i; // find last letter of the last word
        while(i >= 0 && s[i] != ' '){
            i --;
        }
        start = i + 1; // find beg of the last word

        // appending logic
        for(int j=start; j<=end; j++){
            output.push_back(s[j]);
        }
        output.push_back(' '); // appending a space after each word inserted

    }

    // before returning remove the last space
    if(!output.empty()){
        output.erase(output.length() - 1, 1);
    }
    return output;
}
// another way to do it

string reverse_words(string s){

    // get rid of the extra spaces.
    int i = 0;
    while(i <= s.length() - 1 && (i + 1) <= s.length() - 1  ){

        // this gets rid of all the spaces except one in front and one in back.
        if(s[i] == ' ' &&  s[i + 1] == ' '){
            s.erase(i,1);
        }
        else{
            i++;
        }
    }
    // remove first & last space
    if(!s.empty() && s[0] == ' ') s.erase(0,1);
    if(!s.empty() && s[s.length()-1] == ' ') s.erase(s.length()-1,1);


    // reverse the string
    reverse_string(s);

    // reverse again each word

    int beg = 0, space_index = 0, end = 0;
    for(beg; beg < s.length()-1; beg++){

        // find till space
        while(space_index != ' ' && space_index < s.length() - 1){
            space_index ++;
        }
        if(space_index > s.length()-1){
            break;
        }
        end = space_index-1;

        // reverse it
        while(beg < end){
            char temp = s[beg];
            s[beg] = s[end];
            s[end] = temp;
            beg ++, end --;
        }
        space_index++;
        beg = space_index + 1, end = space_index + 1;
    }

    return s;

}

void reverse_string(string &s){
    int left = 0, right = s.length()-1;

    while(left < right){
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left ++, right --;
    }
}
int main(){
    string s = "am here ";
    string res = reverseWords(s);

    cout << res << endl;
    
    return 0;
}