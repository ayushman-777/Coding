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

#define int long long int

int util(vector<int> &h, vector<int> &dp, int pos) {
	if (pos >= h.size()) return INT_MAX;
	if (pos == h.size() - 1) return 0;
	if (dp[pos] != -1) return dp[pos];
	return dp[pos] = min(util(h, dp, pos + 1) + abs(h[pos] - h[pos + 1]),
	                     util(h, dp, pos + 2) + abs(h[pos] - h[pos + 2]));

}

void solve() {
	int n;
	cin >> n;
	vector<int> h(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	vector<int> dp(n + 1, -1);
	cout << util(h, dp, 1) << endl;
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	solve();

	return 0;
}
