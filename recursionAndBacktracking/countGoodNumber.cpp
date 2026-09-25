#include<iostream>
#include<cmath>

using namespace std;

long long int binary_exponentiation(long long base, long long exponent, int MOD){

    if(exponent == 0){
        return 1;
    }

    if(exponent & 1){
        // odd number
        long long int half = binary_exponentiation(base, exponent/2, MOD);
        return ( (base % MOD) * half % MOD) * half % MOD;
    }

    long long int half = binary_exponentiation(base, exponent/2, MOD);
    return (half % MOD) * half % MOD;

}


int countGoodNumbers(long long n){

    int MOD = 1000000007;
    // no. of even pos in n
    long long int noOfEvenPos = (n+1)/2;
    long long int noOfOddPos = n/2;

    long long ans = (binary_exponentiation(5, noOfEvenPos, MOD) * binary_exponentiation(4, noOfOddPos, MOD)) % MOD ;

    return ans;

}

int main(){

    long long n = 806166225460393;

    cout << countGoodNumbers(n) << endl;

    return 0;
}