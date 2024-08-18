#include<iostream>
using namespace std;
/* 
    ******** static local variable***********
    static local variable are by default initialized to zero
    their life time is throughout the program 

    *********static member variable***************
    *->declared inside the class body 
    *->also known as class member varable 
    *->they must be defined ouside the class 
    static member variable does not belong to any object but to the whole class 
    there will be only one copy of static member variable for the whole class 
    any object can use the same copy of class varable 
    they can also be used with class name 


 */

// void fun(){
//     static int x;//lifetime is throughout the program --> only single copy is passed throuout the program
//     int y;//not static variable , so it will be destroyed when function ends.
// }
class acount{
    private:
    int balance;//instance member variable
    static float roi;//static member variable and also class variable 
         
    public:
    void setBalance(int bal){
        this->balance = bal;
    }
    static void setRoi(int r){
        //static member functions can only access static variables only 
        //static member functions can be called without object creation
        roi = r;
        cout<<roi<<endl;
    }
};
float acount:: roi = 0; //definition of static member variable outside the class

int main(int argc, char const *argv[])
{
    acount a1;
    a1.setBalance(500);
    a1.setRoi(5);
    acount::setRoi(78);//called without object
    return 0;
}
