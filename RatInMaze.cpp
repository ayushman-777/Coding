// todo this is incomplete
// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    void findPathUtil(vector<vector<int>> &m, int n, vector<string> &res, string ans, int i, int j, vector<vector<int>> &vis) {

        if (i == n - 1 && j == n - 1) {
            res.push_back(ans);
            return;
        }

        vis[i][j] = 1;

        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        char ch[] = {'D', 'L', 'R', 'U'};
        for (int ind = 0; ind < 4; ind++) {
            int newI = i + di[ind];
            int newJ = j + dj[ind];
            if (newI >= 0 && newJ >= 0 && newI < n && newJ < n && m[newI][newJ] == 1 && vis[newI][newJ] == 0) {
                findPathUtil(m, n, res, (ans + ch[ind]), newI, newJ, vis);
            }
        }

        vis[i][j] = 0;

    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
        if (m[0][0] == 0 || m[n - 1][n - 1] == 0) return res;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        findPathUtil(m, n, res, "", 0, 0, vis);
        return res;
    }
};




// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends