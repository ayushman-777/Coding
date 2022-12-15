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

class SGTree {
public:
	vector<int> seg;
	int N = 0;
public:
	SGTree(int n) {
		seg.resize(4 * n + 1);
	}
	void build(int ind, int low, int high, vector<int> &arr) {
		if (low == high) {
			seg[ind] = arr[low];
			N++;
			return;
		}
		int mid = (low + high) / 2;
		build(2 * ind + 1, low, mid, arr);
		build(2 * ind + 2, mid + 1, high, arr);
		seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
	}
	void build(vector<int> &arr) {
		build(0, 0, arr.size() - 1, arr);
	}
	int query(int ind, int low, int high, int l, int r, int &ans) {
		if (l > high || r < low) {
			return 0;
		}
		if (l <= low && r >= high) {
			if (seg[ind] >= 0) ans += seg[ind];
			return seg[ind];
		}
		int mid = (low + high) / 2;
		int left = query(2 * ind + 1, low, mid, l, r, ans);
		int right = query(2 * ind + 2, mid + 1, high, l, r, ans);
		if ((left + right) >= 0)
			ans += left + right;
		return left + right;
	}
	int query(int l, int r) {
		int ans = 0;
		query(0, 0, N, l, r, ans);
		return ans;
	}
};

int solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	cin >> a;

	SGTree sgt(n);
	sgt.build(a);
	dbg(sgt.seg);
	return sgt.query(0, n - 1);
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
