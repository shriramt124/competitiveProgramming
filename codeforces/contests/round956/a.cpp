#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int xc, yc, k;
        cin >> xc >> yc >> k;
        vector<pair<int, int>> points;

        
        for (int i = 1; i < k; ++i) {
            points.push_back({-i, -i});
        }
        
        
        int sum_x = 0, sum_y = 0;
        for (int i = 0; i < k-1; ++i) {
            sum_x += points[i].first;
            sum_y += points[i].second;
        }
        
        int xk = k * xc - sum_x;
        int yk = k * yc - sum_y;
        points.push_back({xk, yk});
        
       
        for (int i = 0; i < k; ++i) {
            cout << points[i].first << " " << points[i].second << endl;
        }
    }
    return 0;
}
