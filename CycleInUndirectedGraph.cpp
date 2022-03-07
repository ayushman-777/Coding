// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

bool vis[100001];
class Solution {
public:
    // Function to detect cycle in an undirected graph.

    bool dfs(int node, int parent, vector<int> adj[]) {
        vis[node] = true;
        for (auto ele : adj[node]) {
            if (!vis[ele]) {
                if (dfs(ele, node, adj))
                    return true;
            } else if (vis[ele] == true && ele != parent) {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        memset(vis, false, V);

        for (int i = 0; i < V; i++) {
            if (!vis[i])
                if (dfs(i, -1, adj)) return true;
        }
        return false;
    }
};

class Solution2 {
public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int node, vector<int> adj[]) {
        queue<pair<int, int>> q;
        q.push({node, -1});
        vis[node] = 1;

        while (!q.empty()) {
            int cur = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto ele : adj[cur]) {
                if (!vis[ele]) {
                    vis[ele] = true;
                    q.push({ele, cur});
                } else if (vis[ele] == true && ele != parent) return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        memset(vis, false, V);

        for (int i = 0; i < V; i++) {
            if (!vis[i])
                if (bfs(i, adj)) return true;
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends