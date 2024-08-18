#include<iostream>
using namespace std;
class complex{
    int a,b;
    public:
    void setData(int x,int y){
        a = x;
        b = y;
    }
    void showdata(){
        cout<<"a "<<a<<" b "<<b<<endl;
    }
    complex operator+(complex c){// binary operator  overloading
        complex temp;
        temp.a = a+c.a;
        temp.b = b+c.b;
        return temp;
    }
    //uniray operator overloading 
   complex operator-(){
      complex temp;
      temp.a = -a;
      temp.b = -b;
      return temp;
   }
   //increment operator overloading (preincrement)
   complex operator++(){
     complex temp;
     temp.a = ++a;
     temp.b = ++b;
     return temp;
   }
   //post increment overloading 
   complex operator++(int){
    complex temp;
    temp.a = a++;
    temp.b = b++;
    return temp;
   }


};
int main(int argc, char const *argv[])
{
    complex c1, c2,c3,c4;
    c1.setData(4,5);
    c2.setData(6,7);
    c3 = c1+c2;
    c4=-c2;
    c4.showdata();
   


    return 0;
}
