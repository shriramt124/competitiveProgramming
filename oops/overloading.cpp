#include<iostream>
using namespace std;

class Complex{
    int a;
    int b;
    public:
   
    void setData(int a,int b){
        this->a = a;
        this->b = b;
    }
    void showData(){
        cout << this->a << " " << this->b << endl;
    }

    Complex operator +(Complex c){
        Complex temp;
        temp.a = this->a + c.a;
        temp.b= this->b + c.b;
        return temp;

    }

    Complex operator *(Complex c){
        Complex temp;
        temp.a = this->a * c.a;
        temp.b = this->b * c.b;
        return temp;
    }
    Complex operator-(Complex c){//overloading of binary operator
        Complex temp;
        temp.a = this->a - c.a;
        temp.b = this->b - c.b;
        return temp;
    }

    Complex operator -(){//overloading of unary operator
        Complex temp;
        temp.a = -a;
        temp.b = -b;
        return temp;
    }

    //preincrement overloading 
    Complex operator ++(){
        Complex temp = *this;
        ++a;
        ++b;
        return temp;
        }
    Complex operator ++(int){
        Complex temp = *this;
        a++;
        b++;
        return temp;
    }
};

int main(int argc, char const *argv[])
{
    Complex c1;
    c1.setData(41, 51);
    Complex c2;
    c2.setData(5, 6);
    // Complex c3 = c1 + c2;//c1 ne + ko call kiya and c2 as an argument paas hua
    // c3.showData();
    // Complex c4 = c1 * c2;
    // c4.showData();
    // Complex c5 = c1 - c2;
    // c5.showData();
    // Complex c6 = -c1;
    // c6.showData();
    Complex c7 = ++c1;
    c7.showData();
    c1.showData();

    Complex c8 = c1++;
    c1.showData();
    c8.showData();
    // Complex c8 = c1++;
    // c8.showData();

    return 0;
}
