#include <bits/stdc++.h>

using std::endl;
using std::max;
using std::vector;

int main() {
	std::ifstream read("lazy.in");

	int n;
	int k;
	read >> n >> k;
	// the side length needed to accomodate the 45 degree rotation
	int new_n = 2 * n - 1;
	// -1's indicate invalid locations
	vector<vector<int>> field(new_n, vector<int>(new_n, -1));

	// read input and store it rotated by 45 degrees
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { read >> field[i + j][n - i + j - 1]; }
	}

	vector<vector<int>> prefix(new_n + 1, vector<int>(new_n + 1));
	for (int i = 0; i < new_n; i++) {
		for (int j = 0; j < new_n; j++) {
			// prevent including -1's in the prefix sum
			int val = std::max(field[i][j], 0);
			prefix[i + 1][j + 1] =
			    (val + prefix[i + 1][j] + prefix[i][j + 1] - prefix[i][j]);
		}
	}

	int most_grass = 0;
	for (int i = k; i < new_n - k; i++) {
		for (int j = k; j < new_n - k; j++) {
			if (field[i][j] == -1) {
				continue;  // don't start at invalid locations
			}
			most_grass = max(most_grass,
			                 prefix[i + k + 1][j + k + 1] - prefix[i + k + 1][j - k] -
			                     prefix[i - k][j + k + 1] + prefix[i - k][j - k]);
		}
	}

	if (k >= n) {
		// check if Bessie can reach everything
		most_grass = prefix[new_n][new_n];
	}

	std::ofstream("lazy.out") << most_grass << endl;
}