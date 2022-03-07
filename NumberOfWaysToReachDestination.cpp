// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// todo: solution not completed
class Solution {
public:
	int FindWays(int n, int m, vector<vector<int>>blocked_cells) {
		vector<vector<int>> maze(n, vector<int>(m, 1));

		for (auto ele : blocked_cells) {
			maze[ele[0]][ele[1]] = 0;
		}


	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>blocked_cells;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			blocked_cells.push_back({x, y});
		}
		Solution obj;
		int ans = obj.FindWays(n, m, blocked_cells);
		cout << ans << '\n';
	}
	return 0;
}  // } Driver Code Ends