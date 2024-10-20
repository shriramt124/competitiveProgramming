#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2e5 + 5;

int n, q;
int p[MAXN];
char s[MAXN];

int maxLeft[MAXN], minRight[MAXN];

void preprocess() {
    maxLeft[1] = p[1];
    for (int i = 2; i <= n; i++) {
        if (s[i - 1] == 'L') {
            maxLeft[i] = max(maxLeft[i - 1], p[i]);
        } else {
            maxLeft[i] = maxLeft[i - 1];
        }
    }

    minRight[n] = p[n];
    for (int i = n - 1; i >= 1; i--) {
        if (s[i + 1] == 'R') {
            minRight[i] = min(minRight[i + 1], p[i]);
        } else {
            minRight[i] = minRight[i + 1];
        }
    }
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    cin >> (s + 1);

    preprocess();

    while (q--) {
        int i;
        cin >> i;
        char old = s[i];
        s[i] = (old == 'L') ? 'R' : 'L';

        if (i > 1 && old == 'L') {
            maxLeft[i] = max(maxLeft[i - 1], p[i]);
        } else if (i > 1 && old == 'R') {
            maxLeft[i] = maxLeft[i - 1];
        }

        if (i < n && old == 'R') {
            minRight[i] = min(minRight[i + 1], p[i]);
        } else if (i < n && old == 'L') {
            minRight[i] = minRight[i + 1];
        }

        bool ok = true;
        for (int j = 1; j <= n; j++) {
            if (maxLeft[j] > minRight[j]) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
