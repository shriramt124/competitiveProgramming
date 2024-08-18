#include<iostream>
using namespace std;
#include<map>
#include<vector>
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        map<int,bool>m;
        for(int i = 0;i<n;i++){
            cin>>v[i];
            m[v[i]] = false;
        }
        m[v[0]] = true;        bool flag  = true;
        for(int i = 1;i<n;i++){
            int curr = v[i];
            if((m[curr-1] == true) ||( m[curr+1] == true)){
                m[curr] = true;
            }else{
               flag = false;
                break;
            }
        }
        if(flag == true){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
         

        

    }
}