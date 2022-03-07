// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

bool vis[100001], visPath[100001];
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node, vector<int> adj[]) {

        vis[node] = true;
        visPath[node] = true;

        for (auto ele: adj[node]) {
            if (!vis[ele]) {
                if (dfs(ele, adj)) return true;
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
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends