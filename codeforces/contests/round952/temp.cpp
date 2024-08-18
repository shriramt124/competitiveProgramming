#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isBeautifulPossible(vector<int>& a, int k) {
    int n = a.size();

    // No need to perform operations if the array already beautiful
    if (n == 1) return true;

    // Shuffle the array to potentially minimize operations
    random_shuffle(a.begin(), a.end());

    // Sort the array to group matching elements together
    sort(a.begin(), a.end());

    // Calculate differences between corresponding elements
    int operations = 0;
    for (int i = 0; i < n / 2; i++) {
        int diff = abs(a[i] - a[n - i - 1]);

        // Check if it's impossible to make the array beautiful
        if (diff > k) return false;

        operations += diff;
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (isBeautifulPossible(a, k)) {
            cout << "1\n"; // Minimum operations required (beautiful already)
        } else {
            cout << "-1\n"; // Impossible to make beautiful
        }
    }

    return 0;
}
