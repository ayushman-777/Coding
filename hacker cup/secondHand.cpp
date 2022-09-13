#include "bits/stdc++.h"
using namespace std;

bool solve() {
	int n, k;
	map<int, int> mp;
	cin >> n >> k;
	int temp;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		mp[temp]++;
		if (mp[temp] >= 3) {
			flag = false;
		}
	}
	if (flag && (k * 2) >= n) return true;
	else return false;
}

int main() {
	int t = 1;
	cin >> t;
	for (int ind = 1; ind <= t; ind++) {
		cout << "Case #" << ind << ": " << (solve() ? "YES" : "NO") << endl;
	}
	return 0;
}
