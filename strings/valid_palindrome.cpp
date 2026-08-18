#include <iostream>
using namespace std;

void convert_string(string &str)
{
    for(int i = 0; i < str.length(); i++){
        char ch = str[i];
        if(ch >= 65 && ch <= 90){
            str[i] = ch + 32;
        }
        else if(!((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))){
            str.erase(i,1);
            i--;
        }
    }
}
void print_str(string s ){
    for(int i = 0; i < s.length(); i++){
        cout << s[i];
    }
    cout << endl;
}

bool is_palindrome(string s)
{
    int left = 0, right = s.length() - 1;
    while (left < right)
    {
        if (s[left] != s[right])
        {
            return false;
        }
        left++, right--;
    }
    return true;
}

int main()
{

    string s = "A man";
    convert_string(s);
    print_str(s);
    cout << is_palindrome(s) << endl;

    // int ch = 'a'  ;
    // char ch = 'a' + 1;
    // cout << ch << endl;
    // cout << is_palindrome(s) << "endl";
    // print_str(convert_string(s));
    return 0;
}