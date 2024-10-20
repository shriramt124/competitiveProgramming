#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Memoization array
vector<int> memo;

int memoizedSolve(int index, const vector<int>& a, const vector<int>& b) {
    // Base case: if the index is out of bounds
    if (index < 0) {
        return 0;
    }
    
    // Check if the result is already computed
    if (memo[index] != -1) {
        return memo[index];
    }

    // Option 1: Submit the current problem and end the competition
    int submitScore = a[index];

    // Option 2: Skip the current problem
    int nextIndex = b[index] - 1; // Convert 1-based to 0-based index
    int skipScore = memoizedSolve(nextIndex, a, b);
    
    // Store the result in the memo array
    memo[index] = max(submitScore, skipScore);
    return memo[index];
}

int main() {
    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        int n;
        cin >> n; // Read the number of problems
        vector<int> a(n), b(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; // Scores
        }
        
        for (int i = 0; i < n; ++i) {
            cin >> b[i]; // Parameters
        }
        
        // Initialize the memoization array
        memo.assign(n, -1);

        // Calculate maximum points starting from the first problem (index 0)
        int maxPoints = memoizedSolve(0, a, b);
        cout << maxPoints << endl; // Output the result for the current test case
    }
    return 0;
}
