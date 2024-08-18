#include<iostream>
using namespace std;
class B;
class A{
int a;
public:
void setData(int x){
    a = x;
}
friend void fun(A,B);//can be declared private or public no matter
};
class B{
    int b;
public:
    void setData(int x){
    b = x;
}
    friend void fun(A,B);
};

void fun(A o1,B o2){
    cout<<"sum is : "<<o1.a+o2.b<<endl;
}
int main(int argc, char const *argv[])
{
    A obj1;
    B obj2;
    obj1.setData(5);
    obj2.setData(7);
    fun(obj1,obj2);
    return 0;
}
