#include<iostream>
using namespace std;

class smartPhone{
    string model;
    int year_manufacture;
    bool is_5g_support;
    public:
    smartPhone(){//default constructor
        model = "unknown";
        year_manufacture = 0;
        is_5g_support = false;
    }

    //parameterized constructor
    smartPhone(string mod ,int year,bool support){
        year_manufacture = year;
        model = mod;
        is_5g_support = support;
    }

    //copy constructor
    smartPhone(smartPhone &obj){
        year_manufacture = obj.year_manufacture;
        model = obj.model;
        is_5g_support = obj.is_5g_support;
    }
    ~smartPhone(){
        cout << "destructor is called " << endl;
    }
};

int main(int argc, char const *argv[])
{
    smartPhone obj; //it will call the default constructor

    smartPhone obj1("samsung", 4003, true);//it will call the copuy constructor

    smartPhone obj2(obj1);//it will call the copy constructor


    return 0;
}
