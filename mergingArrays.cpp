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

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	cin >> a >> b;
	vector<int> c(n + m);
	int i = 0, j = 0, k = 0;
	while (i < n || j < m) {
		if (j == b.size() || (i < a.size() && a[i] < b[j])) {
			c[k] = a[i];
			i++, k++;
		} else {
			c[k] = b[j];
			j++, k++;
		}
	}
	cout << c << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout.tie(0);

	solve();

	return 0;
}
