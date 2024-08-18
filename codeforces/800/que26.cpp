#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string str;
        cin>>str;
        int start = 0;
        int end = n-1;
        int length = n;
        while (start<end)
        { 
            if(str[start] == '0' and str[end] == '1'){
                length-=2;
                start++;
                end--;
            }else if(str[start] == '1' and str[end] == '0'){
                length-=2;
                start++;
                end--;
            }
            else{
                break;
            }
        }
        cout<<length<<endl;
        
    }
    return 0;
}
