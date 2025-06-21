#include<iostream>
using namespace std;


/*
Shallow Copy


An object is created by simply copying the data of all variables of the original object. Here, the pointer will be copied but not the memory it points to. It means that the original object and the created copy will now point to the same memory address, which is generally not preferred.



Since both objects will reference the exact memory location, then change made by one will reflect those change in another object as well. This can lead to unpleasant side effects if the elements of values are changed via some other reference.  Since we wanted to create an object replica, the Shallow copy will not fulfill this purpose.



Note: C++ compiler implicitly creates a copy constructor and assignment operator to perform shallow copy at compile time.



A shallow copy can be made by simply copying the reference.

*/

class Student {
    int age;
    string str;
    public:
    Student(int age,string str){
        this->age = age;
        this->str = str;
    }

};

 