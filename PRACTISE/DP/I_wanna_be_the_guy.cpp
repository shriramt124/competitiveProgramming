#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

/*

https://codeforces.com/problemset/problem/469/A
 */

int main(){
    int n;
    cin>>n;
    int p;
    cin>>p;
    unordered_map<int,int>m;
      

    vector<int>a(p);
    for(int i = 0;i<p;i++){
     cin>>a[i];
     m[a[i]]++;
    }
    int p1;cin>>p1;
    vector<int>b(p1);
    for(int i = 0;i<p1;i++){
        cin>>b[i];
        m[b[i]++];
    }
    bool flag = true;
    for(int i = 1;i<=n;i++){
        if(m.find(i) == m.end()){
       flag = false;
       break;
        }
    }
    if(flag){
        cout << "I become the guy."<<endl;
    }else{
        cout << "Oh, my keyboard!"<<endl;
    }

    return 0;

    
    
    
}
