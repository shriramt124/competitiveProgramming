#include<iostream>
using namespace std;
class instance{
 int i;
 public:
 instance(int a = 0){
    i = a;
    cout<<i<<" ";
 }
 ~instance(){//on deletion of this funciton print the i
    cout<<i<<" ";
 }
};
instance obj1(2);
int main(int argc, char const *argv[])
{
    instance *pobj = new instance(1);
    instance obj2(3);
    {
        instance obj(4);
        delete pobj; //deleting the object

    }
    return 0;

    
    return 0;
}
