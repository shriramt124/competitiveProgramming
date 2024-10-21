#include<bits/stdc++.h>
using namespace std;

void solv(){
    int n;cin>>n;
    vector<int>arr(n);
    map<int,int>freq;
    int maxFreq = 0;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
      freq[arr[i]]++;
      maxFreq   = max(maxFreq,freq[arr[i]]);
    }
    if(maxFreq == n){
        cout<<0<<endl;
        return;
    }
    if(n == 1){
        cout<<0<<endl;
        return;
    }
    int operation = 0;
    int same = maxFreq;
    int diff = n-maxFreq;
    
    int count = 0;
    while(diff>0){
        if(same < diff){
            operation += same;
            same = same+same;
            diff = n-same;
            count++;   
        }else{
            operation+=diff;
            diff = 0;
            count++;

            break;
        }
    }
    cout<<operation+count<<endl;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solv();
    }
}