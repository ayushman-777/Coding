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

bool isCollinear(int x1, int y1, int x2, int y2, int x3, int y3) {
	int area = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
	if (area == 0) return true;
	return false;
}

void solve() {
	int n; cin >> n;
	vector<pair<int, int>> points;
	int x1, y1;
	for (int i = 0; i < n; i++) {
		cin >> x1;
		cin >> y1;
		points.push_back({x1, y1});
	}
	points.push_back({points[0].first, points[0].second});
	x1 = points[0].first;
	y1 = points[0].second;
	int x2 = points[1].first;
	int y2 = points[1].second;

	int count = 1;
	for (int i = 2; i <= n; i++) {
		// cout << points[i].first << "   " << points[i].second << "   " << x1 << "   " << y1  << "   " << x2 << "   " << y2 << "   " << count << endl;
		if (!isCollinear(x1, y1, x2, y2, points[i].first, points[i].second)) {
			count++;
		}
		x1 = x2, y1 = y2;
		x2 = points[i].first, y2 = points[i].second;
	}
	cout << count;
}

void solve(int n, vector<int> arr, int l, int r, &ans) {
	if (l >= r) {
		return;
	}
	if (arr[l] > arr[r]) {
		ans += arr[l];
		solve(n, arr, l + 1, r, ans);
	} else {
		ans += arr[r];
		solve(n, arr, l, r + 1, ans);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	solve();

	return 0;
}
