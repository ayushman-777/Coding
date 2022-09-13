#include "bits/stdc++.h"

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == 'F' && s[i + 1] == 'F') {
			s[i] = 'P';
			s[i + 1] = 'P';
		} else if (s[i] == 'F') {
			s[i] = 'P';
			s[i + 1] = 'F';
		}
		if (s[i] == 'P') cnt++;
	}
	if (s[n - 1] == 'P') cnt++;
	cout << cnt << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout.tie(0);

	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}
