#include<iostream>
#include<climits>
using namespace std;
// in this problem you can't use 64 bit integers (long long int, long can't be used) so avoid using it and solve this problem in a smart way. 

// bool isValidBit(long long int num){
//     int validValue = 2147483647;
//     if(num >= -(validValue) && num <= validValue){
//         return 1;
//     }
//     return 0;
// }

// int reverse(int x){
//     long long int reverseNum = 0;
//     int remainder = 0;
//     bool isNegative = false;
//     // handling of negative number
//     if(x < 0){
//         isNegative = true;
//         x = -(x);
//     }

//     while(x > 0){
//         remainder = x % 10;
//         reverseNum = (reverseNum + remainder) * 10;
//         x = x / 10;
//     }
//     reverseNum = reverseNum / 10;

//     if(isNegative){
//         reverseNum = -(reverseNum);
//     }
//     if(isValidBit(reverseNum)){
//         return reverseNum;
//     }
//     return 0;

// }

// understand it properly, dry run it. (done)
int reverse(int x){
    if(x > INT_MAX || x < INT_MIN){
        return 0;
    }
    int rev = 0;
    int remainder = 0;
    while(x){
        remainder = x % 10;
        if( ((rev > INT_MAX/10) || (rev == INT_MAX/10 && remainder > 7)) || ((rev < INT_MIN/10) || rev == INT_MIN/10 && remainder < -8)){
            return 0;
        }
        rev = (rev*10) + remainder;
        x = x / 10;
    }
    return rev;
}


int main(){
    int x = 321;
    cout << reverse(x) << endl;
    return 0;
}