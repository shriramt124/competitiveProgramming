#include<bits/stdc++.h>
using namespace std;
#define int long long

//https://codeforces.com/gym/104002/problem/E
//this is how we can choose the element in array greedly if we want to maximize the sum 

signed main(){
    int n;
    cin>>n;
    vector<int>arr(n);  
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

     multiset<int>taken;
     taken.insert(max(arr[0],arr[1]));

     for(int i =2;i<n;i+=2){
        int smallestTaken  = *taken.begin();
        //take the value using the pointer
        if(smallestTaken < min(arr[i],arr[i+1])){
          //remove this and insert the maxo if the two
          taken.erase(taken.begin());
          taken.insert(arr[i]);
          taken.insert(arr[i+1]);
        }else{
            taken.insert(max(arr[i],arr[i+1]));
        }
     }
     int sum = 0;
     for(auto ele:taken) sum+=ele;
     cout<<sum<<endl;

    return 0;
}
/* 
https://codeforces.com/gym/104002/problem/E

 */