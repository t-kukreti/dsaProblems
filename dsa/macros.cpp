#include<iostream>
using namespace std;
#define PI 3.14 //creating a macro
// no extra space is required and before compilation it will replace PI with value of pi (3.14)
// this is not a modifyiable value 

int main(){
    int r = 5;
   // double pi = 3.14; storage was used 8 bytes
    double area = PI*r*r;
    cout << "Area is " << area << endl;
    return 0;
}