#include<iostream>
using namespace std;

class Complex{
    int a;
    int b;
    public:
   
    void setData(int x,int y){
        this->a = x;
        this->b = y;
    }
    friend Complex operator+(Complex, Complex);

    void showData(){
        cout << this->a << " " << this->b << endl;
    }
};

Complex operator +(Complex c1,Complex c2){
    Complex temp;

    temp.a = c1.a + c2.a;
    temp.b = c1.b + c2.b;
    return temp;
}

int main(int argc, char const *argv[])
{
    Complex c1;
    Complex c2;
    c1.setData(2, 4);
    c2.setData(5, 6);
    Complex c3 = c1 + c2;
    c3.showData();

    return 0;
}


