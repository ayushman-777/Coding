#include "bits/stdc++.h"

using namespace std;

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;

void applyAllDirection(vector<int> &forces, int initial, int ind, bool &flag) {
	if ((unsigned)ind == forces.size() || initial == 0 || flag) {
		if (flag) return;
		if (initial == 0) flag = true;
		return;
	}

	initial += forces[ind];
	applyAllDirection(forces, initial, ind + 1, flag);
	initial -= forces[ind];

	initial -= forces[ind];
	applyAllDirection(forces, initial, ind + 1, flag);
	initial += forces[ind];

}

int main() {
	int n;
	cin >> n;
	int initial;
	cin >> initial;
	string direction;
	cin >> direction;

	vector<int> forces;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		forces.push_back(temp);
	}
	bool ans = false;
	applyAllDirection(forces, initial, 0, ans);
	if (ans) {
		cout << "Possible";
	} else {
		cout << "Not Possible";
	}
	return 0;
}
