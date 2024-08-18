#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;   
    while (t--) {
        int n;
        cin >> n;   
        vector<int> p(n), q(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> p[i];  
        }
        
         
        q[0] = p[n - 1];
        for (int i = 1; i < n; ++i) {
            q[i] = p[i - 1];
        }
       
        for (int i = 0; i < n; ++i) {
            cout << q[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

/* 
Therefore, the problem boils down to minimizing the number of subarrays where the sums match between 
p 
and 
𝑞
 */