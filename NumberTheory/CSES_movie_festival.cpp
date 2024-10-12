#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
static bool cmp(pair<int,int>p1,pair<int,int>p2){
    return p1.second < p2.second;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>v;
    for(int i = 0;i<n;i++){
        pair<int,int>p;
        cin>>p.first>>p.second;
         v.push_back(p);
    }
    sort(v.begin(),v.end(),cmp);
    int prev = v[0].second;
    int count = 1;
    for(int i = 1;i<n;i++){
        if(v[i].first >=prev){
            count++;
            prev = v[i].second;
        }
    }
    cout<<count<<endl;

    return 0;
}