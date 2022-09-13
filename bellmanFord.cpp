#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges) {

		vector<int> dist(n, INT_MAX);
		dist[0] = 0;

		for (int i = 0; i < n - 1; i++) {
			for (auto ele : edges) {
				int u = ele[0];
				int v = ele[1];
				int wt = ele[2];
				if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
					dist[v] = dist[u] + wt;
				}
			}
		}
		for (auto ele : edges) {
			int u = ele[0];
			int v = ele[1];
			int wt = ele[2];
			if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
				return 1;
			}
		}
		return 0;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for (int i = 0; i < m; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x, y, z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends