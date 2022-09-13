#include<bits/stdc++.h>
using namespace std;


int dx[] = { -1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isPossible(vector<string> &vec, int i, int j, int r, int c) {
	int newI, newJ, cnt = 0;
	for (int k = 0; k < 4; k++) {
		newI = dx[k] + i;
		newJ = dy[k] + j;
		if (newI >= 0 && newJ >= 0 && newI < r && newJ < c &&
		        (vec[newI][newJ] == '.' || vec[newI][newJ] == '^'))
			cnt++;
	}
	return (cnt >= 2);
}

pair<pair<bool, bool>, vector<string>> solve() {
	int r, c;
	cin >> r >> c;
	vector<string> vec(r);
	bool flag = true;
	for (int i = 0; i < r; i++) {
		cin >> vec[i];
		if (flag) for (int j = 0; j < c; j++) {
				if (vec[i][j] == '^') flag = false;
			}
	}
	if (flag) return {{true, true}, vec};

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (vec[i][j] == '^' && !isPossible(vec, i, j, r, c))
				return {{false, false}, vec};
			if (vec[i][j] == '.' && !isPossible(vec, i, j, r, c))
				vec[i][j] = '*';
		}
	}
	return {{true, false}, vec};
}

int main() {
	freopen("b2.txt", "w", stdout);
	freopen("second_second_friend_input.txt", "rt", stdin);
	int t;
	cin >> t;
	for (int k = 1; k <= t; k++) {
		pair<pair<bool, bool>, vector<string>> pr = solve();
		if (pr.first.first && !pr.first.second) {
			cout << "Case #" << k << ": " << "Possible" << endl;
			int r = pr.second.size(), c = pr.second[0].size();
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (pr.second[i][j] == '.') {
						if (!isPossible(pr.second, i, j, r, c)) {
							cout << pr.second[i][j];
						} else cout << '^';
					} else if (pr.second[i][j] == '*') cout << '.';
					else cout << pr.second[i][j];
				}
				cout << endl;
			}
		} else if (pr.first.first && pr.first.second) {
			cout << "Case #" << k << ": " << "Possible" << endl;
			for (auto &ele : pr.second) cout << ele << endl;
		} else cout << "Case #" << k << ": " << "Impossible" << endl;
	}
	return 0;
}