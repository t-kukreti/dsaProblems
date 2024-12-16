#include<iostream>
using namespace std;
// inline functions are used to reduce the functions calls overhead
void func(int a , int b){
    a++ , b++;
    cout << a << b << endl;
}
// inline func are generally for smaller function like one line maybe 2-3 but depends upon compiler , if you want to read about it read it on stackoverflow
inline int getmax(int& a , int& b){
   return (a>b) ? a : b ;
}
int main(){
    int a = 1 , b = 2;
   // func(a,b);
   int ans = 0;
   getmax(a,b);
   cout << ans <<  endl;
   a = a + 3;
   b = b + 1;
   getmax(a,b);
    
    return 0;
}