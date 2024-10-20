#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

static bool cmpRam(vector<int>&a,vector<int>&b) {
      double first = ((a[0]+a[1])*1.0)/2;
      double second = ((b[0]+b[1])*1.0)/2;
      return first<second;
}
void solveByRam() {
    int n;
    cin >> n;
    
    
    vector<vector<int>>arrays(n,vector<int>(3,0));

    
   
    for (int i = 0; i < n; ++i) {
         cin>>arrays[i][0]>>arrays[i][1];
        arrays[i][2] = max(arrays[i][0],arrays[i][1]);
    }


    
 
    sort(arrays.begin(), arrays.end(), cmpRam);
   
    
   
    for (int i = 0; i < n; ++i) {
        cout <<arrays[i][0]<<" "<<arrays[i][1]<<" ";
    }
    cout << endl;
}

signed main() {
    int t;
    cin >> t;
    
    while (t--) {
        solveByRam();
    }
    
    return 0;
}
