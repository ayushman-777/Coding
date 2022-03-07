// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool isCyclic(int node, vector<bool> &vis, vector<int> adj[], vector<bool> &visPath) {
        vis[node] = true;
        visPath[node] = true;

        for (auto ele : adj[node]) {
            if (!vis[ele]) {
                if (isCyclic(ele, vis, adj, visPath)) return true;
            }
            else if (visPath[ele] == true) return true;
        }

        visPath[node] = false;
        return false;
    }
    bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
        vector<int> adj[N];
        for (auto ele : prerequisites)
            adj[ele.second].push_back(ele.first);

        vector<bool> vis(N, false), visPath(N, false);
        for (int i = 0; i < N; i++) {
            for (auto ele : adj[i]) {
                if (!vis[i])
                    if (isCyclic(ele, vis, adj, visPath)) return false;
            }
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends