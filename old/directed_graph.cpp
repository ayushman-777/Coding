//
// Created by patha on 10-11-2021.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    int count = 0;
    vector<int> inDegree(n, 0);
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        inDegree[y]++;
    }
    queue<int> que;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        count++;
        int cur = que.front();
        que.pop();
        cout << cur << "  ";
        for (auto it: adj[cur]) {
            inDegree[it]--;
            if (inDegree[it] == 0) {
                que.push(it);
            }
        }
    }
    return 0;
}