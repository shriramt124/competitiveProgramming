#include<iostream>
#include<vector>
using namespace std;
void solv(vector<int>v,vector<int>ans,int idx){
    if(idx>=v.size()){
        //print the ans vector 
        for(auto ele:ans){
            cout<<ele<<" ";
        }cout<<endl;
        return;
    }

    //ek bar mat lo 
    solv(v,ans,idx+1);
    ans.push_back(v[idx]);//ek bar lelo
    solv(v,ans,idx+1);

}
int main(int argc, char const *argv[])
{
    vector<int>v = {3,1,2};
    vector<int>ans;
    solv(v,ans,0);
    return 0;
}
