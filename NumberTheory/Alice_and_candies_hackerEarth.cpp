#include <iostream>
#include<vector>
using namespace std;
const int N = 1e9+7;

int main() {
	 int n;
     cin>>n;
      int size = n/2+1;
     vector<int>prefix(size,0);
     
     for(int i = 1;i<=size;i++){
      prefix[i] = i*i;
     }
     for(int i = 0;i<=size;i++){
      cout<<prefix[i]<<" ";
     }cout<<endl;
     int count = 0;
     int i = 1;
     int j = 1;
     while(j<=size and i<=size){
        if((prefix[j]-prefix[i-1]) == n){
     
            count++;
            i = j;
            j++;
        }

     
         else if(prefix[j]-prefix[i-1]<n){
            j++;
         }
         else if(prefix[j]-prefix[i-1] > n){
            i++;
         }
     }
     cout<<count<<endl;
}