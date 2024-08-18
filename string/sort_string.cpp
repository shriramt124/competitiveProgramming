#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
int main(int argc, char const *argv[])
{
    string str = "codingwallah";
    sort(str.begin(),str.end());
    cout<<str<<endl;
    return 0;
}
