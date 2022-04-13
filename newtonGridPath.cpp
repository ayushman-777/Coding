#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;

bool isValid(int i, int j, int n, int m, vector<vector<int>> grid) {
	if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] > 0) {
		return true;
	}
	return false;
}

// https://my.newtonschool.co/playground/code/k7pgam1djznn/

const int dx[] = {0, 1};
const int dy[] = {1, 0};
void backtrack(vector<vector<int>> grid, int i, int j, bool &ans) {
	cout << grid[i][j] << endl;
	if (i == grid.size() && j == grid[0].size()) {
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] != 0) {
					return;
				}
			}
		}
		ans = true;
		return;
	}

	grid[i][j] -= 1;
	backtrack(grid, i, j, ans);
	cout << grid[i][j] << endl;
	grid[i][j] += 1;

	if (!ans) {
		grid[i][j] -= 1;
		for (int k = 0; k < 2; k++) {
			int newI = i + dx[k];
			int newJ = j + dy[k];

			if (isValid(newI, newJ, grid.size(), grid[0].size(), grid)) {
				backtrack(grid, newI, newJ, ans);
			}
		}
		grid[i][j] += 1;
	}
}

void solve() {
	int n, m, temp;
	cin >> n;
	cin >> m;
	vector<vector<int>> grid(n, vector<int> (m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			grid[i][j] = temp;
		}
	}
	bool ans = false;
	if (n == m && n == 1) ans = true;
	else backtrack(grid, 0, 0, ans);
	if (ans) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}
