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

int util(vector<int> &h, vector<int> &dp, int &k, int pos) {
	if (pos >= h.size()) return h[h.size() - 1];
	if (pos == h.size() - 1) return dp[pos] = 0;
	if (dp[pos] != -1) return dp[pos];
	int ans = INT_MAX;
	for (int i = 1; i <= k; i++) {
		ans = min(ans, util(h, dp, k, pos + i) + abs(h[pos] - h[pos + i]));
	}
	return dp[pos] = ans;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> h;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		h.push_back(temp);
	}
	vector<int> dp(n, -1);
	cout << util(h, dp, k, 0) << endl;

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	solve();

	return 0;
}
