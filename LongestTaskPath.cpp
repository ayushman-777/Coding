#include "bits/stdc++.h"
using namespace std;

void seperateByChar(string str, vector<string> &vec) {
	stringstream ss(str);

	while (ss.good()) {
		string substr;
		getline(ss, substr, '.');
		vec.push_back(substr);
	}
}

void seperateByChar(string str, vector<int> &vec, int &graphSize) {
	stringstream ss(str);

	while (ss.good()) {
		string substr;
		getline(ss, substr, ',');
		vec.push_back(stoi(substr));
		graphSize = max(graphSize, stoi(substr));
	}
}

bool vis[100001], visPath[100001];
bool dfs(int node, vector<int> adj[]) {

	vis[node] = true;
	visPath[node] = true;

	for (auto ele : adj[node]) {
		if (!vis[ele]) {
			if (dfs(ele, adj)) return true;
			vis[ele] = true;
		} else if (vis[ele] && visPath[ele]) return true;
	}

	visPath[node] = false;
	return false;
}
bool isCyclic(int V, vector<int> adj[]) {
	memset(vis, false, V);
	memset(visPath, false, V);

	for (int i = 0; i < V; i++) {
		if (!vis[i])
			if (dfs(i, adj)) return true;
	}
	return false;
}

int longestPath(int n, vector<int> adj[], int ind) {
	if ((unsigned)adj[ind].size() == 0) return 1;

	int ans = 0;
	for (auto ele : adj[ind]) {
		ans = max(ans, 1 + longestPath(n, adj, ele));
	}

	return ans;
}

void solve() {
	string str;
	cin >> str;
	vector<string> vec;
	bool isError = false;
	seperateByChar(str, vec);
	vector<int> adj[100005];

	int u, v = stoi(vec[0]);
	unordered_set<int> st;
	st.insert(v);
	int graphSize = v;
	for (int i = 1; i < (unsigned)vec.size() - 1; i++) {
		string temp = vec[i].substr(0, (unsigned)vec[i].size() - 2);
		string temp2 = temp.substr(1, (unsigned)temp.size() - 2);
		if (temp2 != "") {
			stringstream ss2(temp2);
			while (ss2.good()) {
				string substr2;
				getline(ss2, substr2, ',');
				adj[stoi(substr2)].push_back(v);
				graphSize = max(graphSize, stoi(substr2));
			}
		}
		v = vec[i][(unsigned)vec[i].size() - 1] - '0';
		if (st.find(v) != st.end()) {
			cout << "error";
			return;
		}
		st.insert(v);
		graphSize = max(graphSize, v);
	}

	vector<int> temp;
	seperateByChar(vec[(unsigned)vec.size() - 1].substr(1, (unsigned)vec[(unsigned)vec.size() - 1].size() - 2), temp, graphSize);
	for (auto ele : temp) {
		adj[ele].push_back(v);
	}

	// for (int i = 0; i <= graphSize; i++) {
	// 	cout << i << " -> ";
	// 	for (auto ele : adj[i]) cout << ele << "   ";
	// 	cout << endl;
	// }

	if (isCyclic(graphSize, adj)) {
		cout << "error";
		return;
	}

	// vector<int> path(graphSize, -1);
	int ans = 0;
	for (int i = 1; i < (unsigned)graphSize; i++) {
		ans = max(ans, longestPath(graphSize, adj, i));
	}
	cout << ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	solve();

	return 0;
}
