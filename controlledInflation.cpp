// https://codingcompetitions.withgoogle.com/codejam/round/000000000087711b/0000000000accfdb#problem


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
#define loop(i, ini, n) for (int i = ini; i <= n; i++)

// recursion approach
int fucc(vector<pair<int, int>> &minMax, int ind, int ans, int prev) {
	if (ind == minMax.size()) return ans;
	return min(fucc(minMax, ind + 1, ans + minMax[ind].second - minMax[ind].first + abs(prev - minMax[ind].second), minMax[ind].first),
	           fucc(minMax, ind + 1, ans + minMax[ind].second - minMax[ind].first + abs(prev - minMax[ind].first), minMax[ind].second));
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int T = 1;
	cin >> T;
	vector<int> ans;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> a(n + 1, {LLONG_MAX, 0});
		a[0] = {0, 0};
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				int temp;
				cin >> temp;
				if (a[i].first > temp) {
					a[i].first = temp;
				}
				if (a[i].second < temp) {
					a[i].second = temp;
				}
			}
		} // DP approach
		int dp[n + 1][2];
		dp[0][0] = dp[0][1] = 0;

		loop(i, 1, n) {
			dp[i][0] = a[i].second - a[i].first + min(dp[i - 1][0] + abs(a[i - 1].first - a[i].second),
			           dp[i - 1][1] + abs(a[i - 1].second - a[i].second));
			dp[i][1] = a[i].second - a[i].first + min(dp[i - 1][0] + abs(a[i - 1].first - a[i].first),
			           dp[i - 1][1] + abs(a[i - 1].second - a[i].first));

			// cout << i << " : " << dp[i][0] << ' ' << dp[i][1] << '\n';
		}

		ans.push_back(min(dp[n][0], dp[n][1]));
	}
	int i = 1;
	for (auto ele : ans) {
		cout << "Case #" << i << ": " << ele << endl;
		i++;
	}
	return 0;
}
