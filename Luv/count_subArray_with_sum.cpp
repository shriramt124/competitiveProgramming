#include<iostream>
using namespace std;
#include<vector>
/* 
for each test case return a vector v in which v[i] denotes the no of subarray with sum i 
 */
int main(int argc, char const *argv[])
{
    int n;
    cout<<"enter no of subarray "<<endl;
    cin>>n;
    vector<int>v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    vector<int>count(n+1,0);
    for(int i = 0;i<n;i++){
        int sum = 0;
        int j = i;
        while(j<n and sum<=n ){
            sum+=v[j];
            if(sum<=n){
                count[sum]++;
            }
            ++j;
        }
    }
    for(int i = 0;i<n;i++){
        cout<<count[i]<<" ";
    }cout<<endl;
    
    return 0;
}
