#include<iostream>
using namespace std;
#include<vector>
int main(int argc, char const *argv[])
{
    string str = "aaaaAAbbbacccc";
    vector<int>v(str.length()+1,0);
    for(int i = 0;i<str.length();i++){
        v[str[i]]++;
    }
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<" ";
    }cout<<endl;

    int length = 0;
    bool isOdd = false;
    for(int i = 0;i<v.size();i++){
        if(v[i]%2!=0 and v[i]!=0){
            length = length+ v[i]-1;
            v[i] = 1;
            isOdd = true;

        }else if(v[i]%2 == 0 and v[i]!=0){
            length+=v[i];
            v[i] = 0;
        }
    }
    if(isOdd){
    cout<<"length is : "<<length+1<<endl;
    }else{
        cout<<"length is : "<<length<<endl;
    }
    

    return 0;
}
