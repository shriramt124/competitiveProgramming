#include <iostream>
using namespace std;
 class a{
    public:
virtual  void fun()  = 0;

 };
 class b{
    public:
    virtual void fun(){}
 };
 class c{
    int x;
    public:
     void fun();
 };
 int main(int argc, char const *argv[])
 {
    cout<<sizeof(a)<<" "<<sizeof(b)<<" "<<sizeof(c)<<endl;
    return 0;
 }
 