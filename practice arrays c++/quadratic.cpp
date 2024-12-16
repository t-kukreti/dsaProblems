#include<iostream>
#include<math.h>
using namespace std;

int a,b,c;

void displayequation(){
    cout<<"This is your equation "<<a<<"x^2"<<b<<"x"<<c<<endl;
}
void valueofx(int a, int b, int c){
int x1,x2;
int D = sqrt(pow(b,2)-4*a*c); 
cout<<"This is D "<<D<<endl;
x1 = (-b+sqrt(pow(b,2)-4*a*c))/2*a;
x2 = (-b-sqrt(pow(b,2)-4*a*c))/2*a;
cout<<"This is your first value of x(x1) "<<x1<<endl;
cout<<"This is your second value of x(x2) "<<x2<<endl;

}
int main(){
    
    cout<<"Enter a with sign "<<endl;
    cin>>a;
    cout<<"Enter b with sign  "<<endl;
    cin>>b;
    cout<<"Enter c with sign  "<<endl;
    cin>>c;
    displayequation();
    valueofx(a,b,c);

    
    return 0;
}