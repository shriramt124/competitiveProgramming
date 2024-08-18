#include<iostream>
using namespace std;
bool isPalindrome(string str,int i){
    if(i>=str.length()/2){
        return true;
    }
    if(str.at(i) == str.at(str.length()-i-1)){
       return isPalindrome(str,i+1);
    }else{
        return false;
        
    }
}
int main(int argc, char const *argv[])
{
    string str = "11211";
   int res = isPalindrome(str,0);
   cout<<res<<endl;

    return 0;
}
