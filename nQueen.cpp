// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool isValid(vector<vector<int>> brd, int n, int i, int j) {

        int di[] = { -1, 1, 0};
        int dj[] = { -1, -1, -1};

        for (int ind = 0; ind < 3; ind++) {
            int newI = i + di[ind];
            int newJ = j + dj[ind];
            while (newI >= 0 && newJ >= 0 && newI < n && newJ < n) {
                if (brd[newI][newJ] == 1)
                    return false;
                newI += di[ind];
                newJ += dj[ind];
            }
        }
        return true;
    }
    void nQueenUtil(vector<vector<int>> &brd, int n, int j, vector<vector<int>> &ans, vector<int> &res) {
        if (res.size() == n) {
            ans.push_back(res);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isValid(brd, n, i, j)) {
                brd[i][j] = 1;
                res.push_back(i + 1);
                nQueenUtil(brd, n, j + 1, ans, res);
                res.pop_back();
                brd[i][j] = 0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> brd(n, vector<int>(n, 0));
        vector<vector<int>> ans;
        vector<int> res;
        nQueenUtil(brd, n, 0, ans, res);
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
    }
    return 0;
}  // } Driver Code Ends