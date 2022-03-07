//
// Created by patha on 09-11-2021.
//


#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

vi adlist[1000];
bool vis1[1000];
bool vis2[1000];

void dfs(int node) {
    vis2[node] = true;

    for (auto item: adlist[node]) {
        if (!vis2[item]) {
            dfs(item);
        }
    }
    cout << node << endl;
}

int main() {
    int n, m; // n -no. of vertex, m -no. of edges
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        vis1[i] = false;
        vis2[i] = false;
    }
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        adlist[x].push_back(y);
        adlist[y].push_back(x);
    }
    for (int k = 1; k <=n; k++) {
        cout << k << " -> ";
        for (auto i: adlist[k]) {
            cout << i << "  ";
        }
        cout << endl;
    }

    cout << "BFS from here" << endl;
    queue<int> que;
    que.push(1);
    vis1[1] = true;

    while (!que.empty()) {
        int node = que.front();
        que.pop();
        cout << node << endl;
        for (auto item: adlist[node]) {
            if (!vis1[item]) {
                vis1[item] = true;
                que.push(item);
            }
        }
    }
    cout << "DFS from here " << endl;
    dfs(1);
    return 0;
}