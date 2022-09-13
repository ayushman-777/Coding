#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int shortestDist(int i, int j, int destI, int destJ, int n, int m) {
	return (abs(destI - i) + abs(destJ - j)) + 1;
}

int maximumLoot(int T, vector<pair<int, int>> &lootDist, int i, vector<vector<int>> &dp) {
	if (i < 0) return 0;
	if (dp[i][T] != -1) return dp[i][T];

	if (lootDist[i].second > T) {
		dp[i][T] = maximumLoot(T, lootDist, i - 1, dp);
		return dp[i][T];
	}
	else {
		dp[i][T] = max(lootDist[i].first + maximumLoot(T - lootDist[i].second, lootDist, i - 1, dp),
		               maximumLoot(T, lootDist, i - 1, dp));
		return dp[i][T];
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	int x, y;
	cin >> x >> y;
	int time;
	cin >> time;
	int temp;
	vector<pair<int, int>> lootDist;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			int dist = shortestDist(x, y, i, j, n, m);
			lootDist.push_back({temp, (2 * dist - 1)});
		}
	}

	vector<vector<int>> dp(lootDist.size(), vector<int>(time + 1, -1));

	cout << maximumLoot(time, lootDist, lootDist.size() - 1, dp);

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	solve();

	return 0;
}

