//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int f(int val[], int wt[], int i, int w, vector<vector<int>> &dp) {
        if (w == 0) return 0;
        if (w < 0 or i < 0) return INT_MIN;
        if (dp[i][w] != -1) return dp[i][w];
        int inc = f(val, wt, i, w - wt[i], dp);
        int exl = f(val, wt, i - 1, w, dp);
        if (inc != INT_MIN) return max(val[i] + inc, exl);
        return exl;
    }
    int knapSack(int N, int W, int val[], int wt[]) {
        // vector<vector<int>> dp(N, vector<int>(W + 1, 0));
        vector<int> prev(W + 1, 0), cur(W + 1, 0);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= W; j++) {
                if (i == 0 or j == 0) {
                    // dp[i][j] = wt[i] == j ? val[i] : 0;
                    cur[j] = (j % wt[i]) == 0 ? val[i] * (j / wt[i]) : 0;
                    continue;
                }
                int inc = 0, exl = 0;
                // if ((j - wt[i]) >= 0) inc = dp[i][j - wt[i]] + val[i];
                if ((j - wt[i]) >= 0) inc = cur[j - wt[i]] + val[i];
                // exl = dp[i - 1][j];
                exl = prev[j];
                // dp[i][j] = max(inc, exl);
                cur[j] = max(inc, exl);
            }
            prev = cur;
        }
        // return dp[N - 1][W];
        return cur[W];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, W;
        cin >> N >> W;
        int val[N], wt[N];
        for (int i = 0; i < N; i++)
            cin >> val[i];
        for (int i = 0; i < N; i++)
            cin >> wt[i];

        Solution ob;
        cout << ob.knapSack(N, W, val, wt) << endl;
    }
    return 0;
}
// } Driver Code Ends