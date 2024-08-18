#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int mini = INT32_MAX;
  for(int i = 0;i<n;i++){
      mini = min(mini,abs(arr[i]));
  }
  cout<<mini<<endl;
    
    return 0;
}
