#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9+7;
const int MAXN = 1e5+5;

vector<vector<int>>C(MAXN,vector<int>(MAXN));


signed main() {
    int t;
    cin >> t;
    
    // Read inputs
    vector<int> n(t), k(t);
    for (int i = 0; i < t; ++i) cin >> n[i];
    for (int i = 0; i < t; ++i) cin >> k[i];
    
    // Precompute C[n][k] for all n, k <= 10^5 using the wrong formula
    for (int i = 0; i < MAXN; ++i) C[i][0] = 1;  // Base case: C[n][0] = 1 for all n
    for (int i = 1; i < MAXN; ++i) {
        for (int j = 1; j <= i; ++j) {
            C[i][j] = (C[i-1][j] + C[i][j-1]) % MOD;
        }
    }
    
    // Answer each query
    for (int i = 0; i < t; ++i) {
        cout << C[n[i]][k[i]] << endl;
    }
    
    return 0;
}
