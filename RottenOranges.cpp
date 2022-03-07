// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
struct ds {
	int x, y, time;
	ds(int _x, int _y, int _time) {
		x = _x;
		y = _y;
		time = _time;
	}
};
class Solution {
public:
	//Function to find minimum time required to rot all oranges.
	int orangesRotting(vector<vector<int>>& grid) {
		queue<ds> q;
		int n = grid.size();
		int m = grid[0].size();

		int cntOranges = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 2) {
					q.push(ds(i, j, 0));
				}
				if (grid[i][j] != 0) {
					cntOranges++;
				}
			}
		}

		int ans = 0, count = 0;

		while (!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			int time = q.front().time;

			q.pop();
			count++;

			ans = max(ans, time);

			int dx[] = { -1, 0, 1, 0};
			int dy[] = {0, 1, 0, -1};

			for (int i = 0; i < 4; i++) {
				int newX = x + dx[i];
				int newY = y + dy[i];

				if (newX >= 0 && newY >= 0 && newX < n && newY < m && grid[newX][newY] == 1) {
					grid[newX][newY] = 2;
					q.push(ds(newX, newY, time+1));
				}
			}
		}
		if (count == cntOranges) return ans;
		else return -1;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends