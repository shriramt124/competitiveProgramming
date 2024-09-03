#include <iostream>
#include <cmath>   
using namespace std;


bool solv(int n, string &s) {
    long long r = sqrt(n);
    if (r * r != n) return false;  
    for (int i = 0; i < r; i++) {
        if (s[i] != '1') return false;
    }

     
    for (int i = n - r; i < n; i++) {
        if (s[i] != '1') return false;
    }
 
    for (int i = 1; i < r - 1; i++) {
        
        if (s[i * r] != '1' || s[(i + 1) * r - 1] != '1') return false;
        
         
        for (int j = 1; j < r - 1; j++) {
            if (s[i * r + j] != '0') return false;
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        if (solv(n, s)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
