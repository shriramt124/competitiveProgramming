#include<iostream>
using namespace std;
int main()
{
     
 try{
    int *p = new int[1000000000];
    cout<<"memory is located"<<endl;
    delete []p;
 }catch(const exception &e){
  cout<<"exception "<<e.what()<<endl;
 }


    return 0;
}
