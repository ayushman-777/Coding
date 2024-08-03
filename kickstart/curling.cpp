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

int distance(int x, int y)
{
	// Calculating distance
	return x * x + y * y;
}

pair<int, int> solve() {
	int rs, rh, n, m;
	cin >> rs >> rh;
	cin >> n;
	vector<int> x(n + 1), y(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
	cin >> m;
	vector<int> z(m + 1), w(m + 1);
	for (int i = 1; i <= m; i++) {
		cin >> z[i] >> w[i];
	}
	int s_red = 0;
	for (int i = 1; i <= n; i++) {
		bool is_scoring = distance(x[i], y[i]) <= (rs + rh) * (rs + rh); // Inside house.
		for (int j = 1; j <= m; j++) {
			is_scoring &= distance(x[i], y[i]) < distance(z[j], w[j]);
		}
		s_red += is_scoring;
	}

	int s_yellow = 0;
	for (int i = 1; i <= m; i++) {
		bool is_scoring = distance(z[i], w[i]) <= (rs + rh) * (rs + rh); // Inside house.
		for (int j = 1; j <= n; j++) {
			is_scoring &= distance(z[i], w[i]) < distance(x[j], y[j]);
		}
		s_yellow += is_scoring;
	}
	return {s_red, s_yellow};
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
