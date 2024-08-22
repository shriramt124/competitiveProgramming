#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
using ll = long long;

bool solv(const string& str, const vector<ll>& v, ll n) {
    if (str.length() != n) return false;

    unordered_map<char, ll> charToInt;
    unordered_map<ll, char> intToChar;
    
    for (ll i = 0; i < n; i++) {
        char c = str[i];
        ll num = v[i];

        if (charToInt.count(c) && charToInt[c] != num) return false;
        if (intToChar.count(num) && intToChar[num] != c) return false;

        charToInt[c] = num;
        intToChar[num] = c;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> num(n);
        for (ll i = 0; i < n; i++) cin >> num[i];

        ll m;
        cin >> m;
        vector<string> str(m);
        for (ll i = 0; i < m; i++) cin >> str[i];

        for (const auto& s : str) {
            bool ans = solv(s, num, n);
            cout << (ans ? "YES" : "NO") << endl;
        }
    }

    return 0;
}
