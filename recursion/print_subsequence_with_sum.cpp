#include<iostream>
#include<vector>
using namespace std;
void solv(vector<int>v,vector<int>ans,int idx,int sum,int targetsum){
    if(idx >= v.size()){
        if(sum == targetsum){
            for(auto ele:ans){
                cout<<ele<<" ";
            }cout<<endl;
        }
        return;
    }
     
    if(sum>targetsum){
        return;
    }

    //ek bar mat lo 
    solv(v,ans,idx+1,sum,targetsum);
    sum+=v[idx];
    ans.push_back(v[idx]);
    solv(v,ans,idx+1,sum,targetsum);
}
int main(int argc, char const *argv[])
{
    vector<int>v = {1,2,1};
    vector<int>ans;
    int sum = 0;
    int targetsum = 2;
    solv(v,ans,0,sum,targetsum);
    return 0;
}
