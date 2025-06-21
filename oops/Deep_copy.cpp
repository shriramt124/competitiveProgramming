#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
#include<cstring>

/*
Deep Copy


An object is created by copying all the fields, and it also allocates similar memory resources with the same value to the object. To perform Deep copy, we need to explicitly define the copy constructor and assign dynamic memory as well if required. Also, it is necessary to allocate memory to the other constructors’ variables dynamically.

A deep copy means creating a new array and copying over the values.

Changes to the array values referred to will not result in changes to the array data referred to.

*/
class Student {
    int age;
    string name;
    public: 
    Student(int age,string str){
        this->age = age;
        this->name = str;
        //this code will automatically create teh deep copy

        /*  In C++, std::string manages memory automatically.

           When you assign this->name = str;, the std::string implementation allocates new memory and copies the characters.

        Even if str goes out of scope, this->name remains valid and unaffected.
  */
    }
};


class Student1{
    int age;
    char *name;
    public:
    Student1(int age,char *name){
        this->age = age;
        //creating the deep copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        //it will create new array and will copy the data 
    }
};