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

int dx[] = { -1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isPossible(vector<string> &vec, int i, int j) {
	int newI, newJ, cnt = 0, r = vec.size(), c = vec[0].size();
	for (int k = 0; k < 4; k++) {
		newI = dx[k] + i;
		newJ = dy[k] + j;
		if (newI >= 0 && newJ >= 0 && newI < r && newJ < c && vec[newI][newJ] != '#') cnt++;
	}
	return (cnt >= 2);
}

int vis[3005][3005];
void bfs(vector<string> &vec, int r, int c) {
	queue<pair<int, int>> q;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!isPossible(vec, i, j)) q.push({i, j});
		}
	}
	while (!q.empty()) {
		int curi = q.front().first;
		int curj = q.front().second;
		q.pop();
		if (vec[curi][curj] == '^' && !isPossible(vec, curi, curj))
			q.push({curi, curj}), vec[curi][curj] = '*';
	}
}

pair<bool, vector<string>> solve() {
	int r, c;
	cin >> r >> c;
	vector<string> vec, adj;
	string ele;
	bool found = false;
	for (int i = 0; i < r; i++) {
		cin >> ele;
		vec.push_back(ele);
		for (auto &ch : ele) {
			if (ch == '^') found = true;
			if (ch != '#') ch = '^';
		}
		adj.push_back(ele);
	}
	if (!found) return {true, vec};
	if (r == 1 || c == 1) return {false, vec};

	bfs(adj, r, c);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (vec[i][j] == '^' && adj[i][j] == '*') {
				return {false, vec};
			}
		}
	}
	return {true, adj};
}

int main() {
#ifdef DEBUG
	freopen("D:/patha/Projects/Competitive Programming/Error.txt", "w", stderr);
	freopen("D:/patha/Projects/Competitive Programming/output.txt", "w", stdout);
#endif
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
			for (auto &ele : pr.second) {
				for (auto &e : ele) {
					if (e == '*') cout << ".";
					else cout << e;
				}
				cout << endl;
			}
		} else cout << "Case #" << ind << ": " << "Impossible" << endl;
		ind++;
	}
	return 0;
}
