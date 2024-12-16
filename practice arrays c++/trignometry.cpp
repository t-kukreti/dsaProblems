#include<iostream>
#include<math.h>
using namespace std;

class trigo{
    float A,B;
    friend void resultant(trigo);
    public:
    trigo(){
        float x, y;
        cout<<"Enter x and y in degrees "<<endl;
        cin>>x>>y;
        x = x*(M_PI/180);
        A=x;
        y=y*(M_PI/180);
        B=y;
    }

    void show(void){
        cout<<"sin("<<A<< "+" <<B<<")"<<endl;
    }
   
    
};
void resultant (trigo t1){
   
    float resultant ;
    resultant = (sin(t1.A)*cos(t1.B) + cos(t1.A)*sin(t1.B));
    cout<<"The resultant is "<<resultant<<endl;
}

int main()
{
  
  trigo t1;
  t1.show();
  resultant(t1);
  //t1.result();
 /*  float x;
    cout<<"Enter x (in degree)"<<endl;
    cin>>x;
 
   
    x=x*(M_PI/180);
   */
    return 0;

}