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
const char nl = '\n';
const int MX = 100001;

#define all(x) x.begin(), x.end()
#define endl '\n'

void solve() {

}

int main() {
#ifdef DEBUG
  freopen("D:/patha/Projects/Competitive Programming/Error.txt", "w", stderr);
#endif
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cout.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    solve();
    dbg(NULL);
  }
  return 0;
}
