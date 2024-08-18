#include<iostream>
using namespace std;
#include<algorithm>
#include<cstring>
int main(int argc, char const *argv[])
{
    int ch = 'a';
  cout<<int(ch)<<endl;//int(ch) --> converting to it's numerical form i.e. ascii code 
  string str = "shriram tiwari";
  reverse(str.begin(),str.end());
  cout<<"reversed string is : "<<str<<endl;
  cout<<str.substr(0,3)<<endl;
  
    return 0;
}
