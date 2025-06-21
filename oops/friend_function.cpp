#include<iostream>
using namespace std;
#include<string>
#include<algorithm>

/*
Characteristics of friend function:

A friend function can be declared in the private or public section of the class.
It can be called a normal function without using the object.
A friend function is not in the scope of the class, of which it is a friend.
A friend function is not invoked using the class object as it is not in the class’s scope.
A friend function cannot access the private and protected data members of the class directly. It needs to make use of a class object and then access the members using the dot operator.
A friend function can be a global function or a member of another class.
*/
class Square;
class Rectangle{
    int length;
    public:
    Rectangle(int a){
        this->length = a;
    }
    friend int showLength(Rectangle);//declaration of friend function //prototype

    friend int sum(Rectangle, Square);
};

class Square{
    int l;
    int b;
    public:
    Square(int a,int b ){
        this->b = b;
        this->l = a;
    }
    friend int sum(Rectangle, Square);
};

int showLength(Rectangle r){
    cout << r.length << endl;
}

int sum(Rectangle r,Square s){
    int ans = r.length + s.b + s.l;
    cout << "sum of sides of Rectangle and Square is " << ans << endl;
    }

int main(int argc, char const *argv[])
{
    Rectangle r(19);
    showLength(r);
    Square s(3, 4);
    sum(r, s);
    return 0;
}
