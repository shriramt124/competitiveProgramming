#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    /* int i = 20;
    float f = static_cast<float>(i);
    //convertiing integer to float
    cout<<f<<endl; */

    /* const int i = 15;
    //const variable can not be modified once it
    //but to modify it we can do const_cast type operator
    int *j = const_cast<int*>(&i);
    cout<<(*j)<<endl; */

   int i = 10;
   int *numPointer = &i;
   char *charPointer = reinterpret_cast<char *>(numPointer);
   cout<<numPointer<<endl;
   cout<<reinterpret_cast<void*>(charPointer)<<endl;



    return 0;
}
