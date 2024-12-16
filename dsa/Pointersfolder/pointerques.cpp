#include<iostream>
using namespace std;
void swap(char *x , char *y){ // Understand this concept
    cout<<"Inside swap " <<endl;
  
    char *t = x;
    x = y ;
    y = t;
      cout<<"This is x " << x <<endl;
    cout<<"This is y " << y <<endl;

}

int main(){
    char *x = "ninjaquiz" ;
    char *y = "codingninjas" ;
    swap(x,y);
    char *t; // dangerous
    cout<<"Swapping with funcion " <<endl;
    cout<<"This is x " << x <<endl;
    cout<<"This is y " << y <<endl;
    t=x;
    x=y;
    y=t;
    cout<<"Swapping directly " <<endl;
    cout<<"This is x " << x <<endl;
    cout<<"This is y " << y <<endl;
    return 0;
}