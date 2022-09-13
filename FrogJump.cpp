/*int util(int ind, vector<int> &heights, vector<int> &dp) {
    if (ind == 0) return 0;
    if (dp[ind] != -1) return dp[ind];
    int jumpTwo = INT_MAX;
    int jumpOne = util(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
    if (ind > 1)
        jumpTwo = util(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);
    return dp[ind] = min(jumpTwo, jumpOne);
}

int frogJump(int n, vector<int> &heights) {
    vector<int> dp(n + 1, -1);
    return util(n - 1, heights, dp);
}*/

int frogJump(int n, vector<int> &heights) {
    int temp1 = 0, temp2 = 0, ans;
    for (int i = 1; i < n; i++) {
        int fs = temp2 + abs(heights[i] - heights[i - 1]);
        int ss = INT_MAX;
        if (i > 1) ss = temp1 + abs(heights[i] - heights[i - 2]);
        ans = min(fs, ss);
        temp1 = temp2;
        temp2 = ans;
    }
    return ans;
}