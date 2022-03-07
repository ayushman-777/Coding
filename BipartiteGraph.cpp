// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int color[100001];
class Solution {
public:
	bool dfs(int node, int curColor, vector<int> adj[]) {
		color[node] = curColor;

		for (auto ele : adj[node]) {
			if (color[ele] == 0) {
				if (!dfs(ele, 3 - curColor, adj)) return false;
			}
			if (color[ele] == color[node]) return false;
		}
		return true;
	}
	bool isBipartite(int V, vector<int>adj[]) {
		memset(color, 0, V);

		for (int i = 0; i < V; i++) {
			if (color[i] == 0)
				if (!dfs(i, 1, adj)) return false;
		}
		return true;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);
		if (ans)cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends