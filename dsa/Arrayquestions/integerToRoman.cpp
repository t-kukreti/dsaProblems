#include<iostream>
#include<map>
using namespace std;
// using map
string convertToRoman(int num){
    string ans;
    map<int, string , greater<int>> romanNumbers = {
        {1, "I"},
        {4 , "IV"},
        {5 , "V"},
        {9 , "IX"},
        {10 , "X"},
        {40 , "XL"},
        {50 , "L"},
        {90 , "XC"},
        {100 , "C"},
        {400 , "CD"},
        {500 , "D"},
        {900 , "CM"},
        {1000 , "M"}
    };
    for(auto it = romanNumbers.begin(); it != romanNumbers.end(); it++){
        while(num >= it->first){
            ans += it->second;
            num -= it->first;
        }
    }
    return ans;
}

string intToRoman(int num){
    if(num > 3999 || num < 1){
        return "not possible ";
    }
    string ans;
    while(num >= 1000){
        ans.push_back('M');
        num -= 1000;
    }

    while(num >= 900){
        ans.push_back('C');
        ans.push_back('M');
        num -= 900;
    }
    while(num >= 500){
        ans.push_back('D');
        num -= 500;
    }
    while(num >= 400){
        ans.push_back('C');
        ans.push_back('D');
        num -= 400;
    }

    while(num >= 100){
        ans.push_back('C');
        num -= 100;
    }
    while(num >= 90){
        ans.push_back('X');
        ans.push_back('C');
        num -= 90;
    }
    while(num >= 50){
        ans.push_back('L');
        num -= 50;
    }
    while(num >= 40){
        ans.push_back('X');
        ans.push_back('L');
        num -= 40;
    }
    while(num >= 10){
        ans.push_back('X');
        num -= 10;
    }
    while(num >= 9){
        ans.push_back('I');
        ans.push_back('X');
        num -= 9;
    }
    while(num >= 5){
        ans.push_back('V');
        num -= 5;
    }
    while(num >= 4){
        ans.push_back('I');
        ans.push_back('V');
        num -= 4;
    }
    while(num >= 1){
        ans.push_back('I');
        num -= 1;
    }

    return ans;


}

int main(){
    int num;
    cout << "Enter a num : ";
    cin >> num;
    cout << endl;

    string ans1 = intToRoman(num);
    string ans2 = convertToRoman(num);

    if(ans1 == ans2){
        cout << " ans is " << ans2 << endl;
    }

    return 0;
}