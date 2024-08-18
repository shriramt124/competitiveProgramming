#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int>arr(n);
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        //calculate the maxdiff 
        int maxdiff = 0;
        maxdiff = arr[0]-0;
        for(int i = 0;i<arr.size()-1;i++){
            maxdiff = max(maxdiff,abs(arr[i]-arr[i+1]));
        }
        
        //atleast maxdiff petrol to hoga hi last petrol pump tak pahuchne ke liye 
        //check kya last petrol pump pe jitna petrol hai kya wo sufficient hai x tak ja ke wapas aane ke liye 
        int reqPetrol = 2*(x-arr[n-1]);
        //check karo ki kya required jyada to nahi hai current se agar hai to jitna jyada utna current me addkar do 
        if(reqPetrol > maxdiff){
            maxdiff = maxdiff + (reqPetrol-maxdiff);
        }
        cout<<maxdiff<<endl;

    }
    return 0;
}
