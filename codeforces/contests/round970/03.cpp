#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long l, r;
        cin >> l >> r;
        
        if (l == r) {
            cout << 1 << endl;  // Only one possible element, length is 1
        } else {
            long long diff = r - l;
            // Calculate the maximum length using the derived formula
            long long n = static_cast<long long>(sqrt(2 * diff))+1;

            // Check if n satisfies the condition
            if (n * (n - 1) / 2 > diff) {
                n--;  // Decrease n until the condition is satisfied
            }

            cout << n << endl;
        }
    }

    return 0;
}
