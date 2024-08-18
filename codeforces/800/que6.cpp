#include<iostream>
using namespace std;
#include<vector>
#include<map>
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int,int>m;
        vector<int>arr(n);
        for(int i = 0;i<n;i++){
            cin>>arr[i];
            m[arr[i]]++;
        }
        if(m.size() == 1){
            cout<<"yes"<<endl;
        }
        else if(m.size() == 2){
            vector<int>v;
            for(auto ele:m){
                v.push_back(ele.second);
            }
            
            if(n%2 == 0){
             if(abs(v[0]-v[1]) == 0){
                cout<<"yes"<<endl;
             }
             else{
                cout<<"no"<<endl;
             }
            }else{
                if(abs(v[0]-v[1]) == 1){
                    cout<<"yes"<<endl;
                }else{
                    cout<<"no"<<endl;
                }

            }
            
        }
        else if(m.size()>2){
            cout<<"no"<<endl;
        }
         
    }
    return 0;
}
