// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(bool graph[101][101], int cur, int n, int curColor, vector<int> color) {
    for (int i = 0; i < n; i++) {
        if (graph[cur - 1][i] && color[i + 1] == curColor) return false;
    }
    return true;
}
bool coloringUtil(bool graph[101][101], int m, int cur, int n, vector<int> &color, int &ans) {
    if (cur == n + 1) {
        // for (auto ele : color) cout << ele << "   ";
        // cout << "# " << cur << "   " << ans << endl;
        for (int i = 1; i <= n; i++) if (color[i] == -1) return false;
        if (ans <= m) return true;
        return false;
    }

    for (int i = 1; i <= m; i++) {
        if (isSafe(graph, cur, n, i, color)) {
            int temp = ans;
            ans = max(ans, i);
            color[cur] = i;
            if (coloringUtil(graph, m, cur + 1, n, color, ans)) return true;
            color[cur] = -1;
            ans = temp;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<int> color(V + 1, -1);
    int ans = 0;
    return coloringUtil(graph, m, 1, V, color, ans);
}



// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
// } Driver Code Ends