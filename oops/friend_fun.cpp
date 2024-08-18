#include<iostream>
using namespace std;
class complex{
 int x,y;
 public:
 void setData(int a,int b){
    x = a;
    y = b;
 }
 void showdata(){
    cout<<"x"<<x<<"y"<<y<<endl;
    
    }
    friend void fun(complex);  //friend function declaration

};

//friend function is defined outside the class without member label 
void fun(complex c){
    cout<<c.x<<" "<<c.y<<endl;
}
int main(int argc, char const *argv[])
{
    complex c1;
    c1.setData(34,56);   //calling method of class using dot operator
   
    fun(c1);

    return 0;
}
