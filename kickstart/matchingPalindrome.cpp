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

bool isPalindrome(string S)
{
	for (int i = 0; i < S.length() / 2; i++) {
		if (S[i] != S[S.length() - i - 1]) {
			return false;
		}
	}
	return true;
}
string allSubstrings2(string &s) {
	int n = s.length();
	for (int i = 0; i < n; i++)
		for (int len = 1; len <= n - i; len++)
			if (isPalindrome(s.substr(i, len)) && isPalindrome(s + s.substr(i, len)))
				return (s.substr(i, len));
}

string solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	return allSubstrings2(s);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout.tie(0);

	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": " << solve() << endl;
	}
	return 0;
}
