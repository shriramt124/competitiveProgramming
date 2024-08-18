#include <iostream>
using namespace std;
#include <vector>
void solv(vector<int> v, int target, int idx, int count,int &ans)
{
    if (idx >= v.size())
    {
        if(target == 0)
        ans = min(ans,count);

        return;
    }
    if(target == 0){
        ans = min(ans,count);
        return;
    }
  
    
    //take the elment of not take the element
 
     //either take or not take it 
     if(target>0)
     solv(v,target-v[idx],idx,count+1,ans);
     if(target>0)
     solv(v,target-v[idx],idx+1,count+1,ans);
     if(target>0)
     solv(v,target,idx+1,count,ans);

 
}
int main()
{

    vector<int> v = {12, 1, 3};
    int target = 4;
    int n = 3;
    int ans = INT8_MAX;
    solv(v,target,0,0,ans);
    cout<<ans<<endl;

    return 0;
}