#include<iostream>
using namespace std;

class human{
    private:
    string name;
    string hairtype;
    string describe;
   
    public:
    int age;
    
void setdata();


void getdata(){
    cout<<endl;
    cout<<"your friend name is : " << name <<endl;
    cout<< "your friend got a " << hairtype << " hairtype "<<endl; 
    cout<<describe<<endl;
    cout<<"your friend is " << age << " years old "<<endl;
};
};
void human :: setdata(){
cout<<"enter name of your friend:"<<endl;
cin>>name;
cout<<"enter hairtype:"<<endl;
cin>>hairtype;
cout<<"describe :"<<endl;
getline(cin>>ws,describe);
}

int main(){
    human sia , anku;
    sia.setdata();
   sia.age = 19;
   
    anku.setdata();
    anku.age = 19;
     sia.getdata();
    anku.getdata();
    
    return 0;
}