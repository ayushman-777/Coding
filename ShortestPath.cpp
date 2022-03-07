// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    struct Node {
        int x, y, dist;
        Node(int _x, int _y, int _dist) {
            x = _x;
            y = _y;
            dist = _dist;
        }
    };

    int shortestDistance(int n, int m, vector<vector<int>> A, int X, int Y) {
        
        if (A[0][0] == 0) return -1;

        int vis[n][m];
        memset(vis, 0, sizeof vis);
        vis[0][0] = 1;
        queue<Node> q;
        q.push(Node(0, 0, 0));


        int dx[] = { -1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int x = q.front().x;
            int y = q.front().y;
            int dist = q.front().dist;
            q.pop();

            if (X == x && y == Y) {
                return dist;
            }

            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
        
                if (newX >= 0 && newY >= 0 && newX < n && newY < m 
                    && A[newX][newY] == 1 && vis[newX][newY] == 0) {
                    vis[newX][newY] = 1;
                    q.push(Node(newX, newY, dist+1));
                }
            }
        }
        return -1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}  // } Driver Code Ends