/*
template allows us to write generic code that works with different data type
*/

#include <iostream>
using namespace std;
template <typename T>
void swap_val(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main(int argc, char const *argv[])
{
    int a = 5;
    int b = 52;
    cout << "Before swapping a : " << a << " b: " << b << endl;
    swap_val(a, b);
    cout << "Before swapping a : " << a << " b: " << b << endl;
    double a1 = 5.34;
    double b1 = 52.2;
    cout << "Before swapping a : " << a1 << " b: " << b1 << endl;
    swap_val(a1, b1);
    cout << "Before swapping a : " << a1 << " b: " << b1 << endl;

    return 0;
}
