// { Driver Code Starts
#include <bits/stdc++.h>
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
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DSU dsu(n * m + 1);
        int count = 0;
        int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
        int dy[] = {0, 0, -1, 1, 1, -1, -1, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '0') continue;

                int ind1 = i * m + j;

                count++;
                for (int k = 0; k < 8; k++) {
                    int newX = i + dx[k];
                    int newY = j + dy[k];

                    // cout << newX << "  " << newY << endl;

                    int ind2 = newX * m + newY;

                    if (newX >= 0 && newY >= 0 && newX < n && newY < m && grid[newX][newY] == '1'
                            && dsu.findParent(ind1) != dsu.findParent(ind2)) {
                        count--;
                        dsu.Union(ind1, ind2);
                    }
                }
                // for (auto ele : dsu.parent) cout << ele << "  ";
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends