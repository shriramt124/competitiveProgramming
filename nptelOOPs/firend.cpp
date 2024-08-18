#include<iostream>
using namespace std;
class test{
int x;
public:
test(int data){
    x = data;
}
friend class retest;
//by using this friend class this private x can be acccessible in the retest class

};

class retest{
    int d;
    public:
    retest(int x){
        d = x;
    }
    void update(const test &r){
        cout<<(d+r.x)<<endl;
    }
};