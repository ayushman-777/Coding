#include "bits/stdc++.h"
using namespace std;

void solve() {
	string s;
	cin >> s;
	int gCount = 0, bCount = 0, evenG = 0, evenB = 0, oddG = 0, oddB = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'G') gCount++;
		else bCount++;
		if (i % 2 == 0) {
			if (s[i] == 'G') evenG++;
			if (s[i] == 'B') evenB++;
		} else {
			if (s[i] == 'G') oddG++;
			if (s[i] == 'B') oddB++;
		}
	}
	if (gCount > bCount) {
		cout << max(oddG, evenB);
	} else if (bCount > gCount) {
		cout << max(oddB, evenG);
	} else {
		// cout << evenG << "  " << evenB << "  " << oddG << "  " << oddB << endl;
		cout << min({evenG, evenB, oddB, oddG});
	}
}

int main() {
	solve();
	return 0;
}
