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

// 1 2 3 4 5
// 1 2 3 2 1

// 1 2 9 1 1
// 1 3 0 3 1

// 9 9 9 2 2
// 1 0 0 0 2 2
// 1 0 0 0 0 1 (insert(s.begin(), 1))

// 1 9 9 1 1

void makePalindrom(string &s, int n) {
    for (int i = n / 2; i > 0; i--) {
        s[n - i] = s[i - 1];
    }
}

void solve() {
    string s;
    cin >> s;
    if (s.length() == 1) {cout << s << endl; return;}
    string temp = s;
    int n = s.length();
    makePalindrom(temp, n);
    if (stoi(s) < stoi(temp)) {
        cout << temp << endl;
    } else {
        int mid = (n + 1) / 2;
        if (s[mid] != '9') {
            s[mid - 1] = (char)(s[mid - 1] + 1);
            makePalindrom(s, n);
            cout << s << endl;
        } else {
            int i;
            for (i = mid; i > 0; i--) {
                if (s[i - 1] != '9') {
                    s[i - 1] = (char)(s[i - 1] + 1);
                    break;
                } else {
                    s[i - 1] = '0';
                }
            }
            if (s[0] == '0') {
                s.insert(s.begin(), '1');
                makePalindrom(s, n + 1);
            } else {
                makePalindrom(s, n);
            }
            cout << s << endl;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cout.tie(0);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
