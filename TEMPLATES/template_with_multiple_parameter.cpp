#include<iostream>
using namespace std;
template<typename T,typename U>
auto multiply(const T&a,const U&b) -> decltype(a*b){
    return a*b;
}

template <typename T,typename U>
auto add(const T&a,const U&b)->decltype(a+b){
    return a+b;
}


int main(int argc, char const *argv[])
{
    int a = 5;
    double b = 2.7;
    cout<<"multiply is : "<<multiply(a,b)<<endl;

    cout<<"addition is : "<<add(a,b)<<endl;
    
    return 0;
}
