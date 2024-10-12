#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int main(){
    int n,x;
    cin>>n>>x;
    vector<pair<int,int> >v;
    for(int i = 0;i<n;i++){
        pair<int,int>p;
        cin>>p.first;
        p.second = i+1;
        v.push_back(p);
    }
    sort(v.begin(),v.end());
    // for(int i = 0;i<n;i++){
    //     cout<<v[i].first<<" "<<v[i].second<<endl;
    // }
    int i = 0;
    int j = n-1;
    while(i<j){
        if(v[i].first+v[j].first == x){
            cout<<v[i].second<<" "<<v[j].second<<endl;
            return 0;
        }else if(v[i].first+v[j].first < x){
            i++;
        }else{
            j--;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
     
}