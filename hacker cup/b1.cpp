#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

using namespace std;

template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v) {for (auto &it : v)cin >> it; return istream;}
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;

#define all(x) x.begin(), x.end()

pair<bool, vector<string>> solve() {
	int r, c;
	cin >> r >> c;
	vector<string> vec(r);
	int cnt = 0;
	cin >> vec;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (vec[i][j] == '^') cnt++;
			vec[i][j] = '^';
		}
	}

	if (cnt == 0) {
		return {true, vector<string>(r, string(c, '.'))};
	} else {
		bool flag = true;
		int dx[] = { -1, 1, 0, 0};
		int dy[] = {0, 0, -1, 1};
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				int temp = 0;
				for (int k = 0; k < 4; k++) {
					int newI = dy[k] + i;
					int newJ = dx[k] + j;
					if (newI >= 0 && newJ >= 0 && newI < r && newJ < c) temp++;
				}
				if (temp <= 1) {flag = false; break;}
			}
		}
		if (flag) return {true, vec};
		return {false, vec};
	}

}

int main() {
	freopen ("second_friend_input.txt", "rt", stdin);
	freopen("b11.txt", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout.tie(0);

	int T = 1;
	cin >> T;
	int ind = 1;
	while (T--) {
		pair<bool, vector<string>> pr = solve();
		if (pr.first) {
			cout << "Case #" << ind << ": " << "Possible" << endl;
			for (auto &ele : pr.second) cout << ele << endl;
		} else cout << "Case #" << ind << ": " << "Impossible" << endl;
		ind++;
	}
	return 0;
}
