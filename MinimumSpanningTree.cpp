// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DSU {
private:
    vector<int> parent, size;
public:
    DSU(int n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
            size.push_back(1);
        }
    }

    int findParent(int node) {
        if (parent[node] == node) return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionSize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.

    bool comp(vector<vector<int>> a, vector<vector<int>> b) {
        if (a[0][1] > a[1][1] && a[1][1] > b[0][1] && b[0][1] > b[1][1])
            return true;
        return false;
    }
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<vector<int>> ad;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                ad.push_back({adj[i][j][1], i, adj[i][j][0]});
            }
        }
        sort(ad.begin(), ad.end());
        DSU dsu(V);
        int ans = 0;

        for (auto ele : ad) {
            cout << ele[0] << "    " << ele[1] << "    " << ele[2] << endl;
            if (dsu.findParent(ele[1]) != dsu.findParent(ele[2])) {
                ans += ele[0];
                dsu.unionSize(ele[1], ele[2]);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends