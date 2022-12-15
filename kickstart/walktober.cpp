#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

using namespace std;
#ifdef DEBUG
#include "D:/patha/Projects/Competitive Programming/debug.h"
#else
#define dbg(x...)
#endif

template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v) {for (auto &it : v)cin >> it; return istream;}
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

const int MOD = 1000000007;
const int mx = 100001;

#define all(x) x.begin(), x.end()
#define endl '\n'

int solve() {
	int m, n, p;
	cin >> m >> n >> p;
	p--;
	int maxi = 0, sum = 0, ans = 0;
	vector<vector<int>> vec(m, vector<int>(n));
	vector<int> sumS(m);
	cin >> vec;

	for (int j = 0; j < n; j++) {
		maxi = 0;
		for (int i = 0; i < m; i++) {
			maxi = max(maxi, vec[i][j]);
		}
		if (maxi > vec[p][j]) ans += maxi - vec[p][j];
	}

	return ans;

	/*for (int i = 0; i < m; i++) {
		sum = 0;
		for (int j = 0; j < n; j++) {
			cin >> vec[i][j];
			sum += vec[i][j];
		}
		sumS[i] = sum;
		maxi = max(maxi, sum);
	}
	set<int> st;
	for (int i = 0; i < m; i++) {
		if (sumS[i] == maxi) {
			st.insert(i);
		}
	}

	p--;
	if (st.find(p) != st.end()) {
		int ans = 0;
		for (int j = 0; j < n; j++) {
			maxi = 0;
			for (auto &ele : st) {
				maxi = max(maxi, vec[ele][j]);
			}
			if (maxi > vec[p][j]) {
				dbg(maxi, vec[p][j]);
				ans += abs(maxi - vec[p][j]);
			}
		}
		return ans;
	} else {
		return abs(maxi - sumS[p]);
	}*/

}

int main() {
#ifdef DEBUG
	freopen("D:/patha/Projects/Competitive Programming/Error.txt", "w", stderr);
#endif
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout.tie(0);

	int T = 1, ind = 1;
	cin >> T;
	while (T--) {
		cout << "Case #" << ind << ": " << solve() << endl;
		ind++;
		dbg(NULL);
	}
	return 0;
}
