// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int bfs(unordered_map<int, int> snake, unordered_map<int, int> ladder, int n) {
        queue<pair<int, int>> que;
        que.push({1, 0});

        while (!que.empty()) {
            int pos = que.front().first;
            int num = que.front().second;
            que.pop();

            cout << pos << endl;
            if (pos == 30) {
                return num;
            }

            for (int i = 1; i <= 6; i++) {
                auto itSnake = snake.find(pos + i);
                auto itLadder = ladder.find(pos + i);
                if (itLadder != ladder.end()) {
                    que.push({(*itLadder).second, num + 1});
                } else if (itSnake != snake.end()) {
                    que.push({(*itSnake).second, num + 1});
                } else {
                    que.push({pos + i, num + 1});
                }
            }

        }
    }
    int minThrow(int N, int arr[]) {
        int ans = 0;
        unordered_map<int, int> snake, ladder;
        for (int i = 0; i < N; i += 2) {
            snake.insert({arr[i], arr[(i) + 1]});
            ladder.insert({arr[i + N], arr[(i) + 1 + N]});
        }
        // for (auto ele : snake) cout << ele.first << "  " << ele.second << endl;;
        // cout << endl;
        // for (auto ele : ladder) cout << ele.first << "  " << ele.second << endl;
        ans = bfs(snake, ladder, N);
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[2 * N];
        for (int i = 0; i < 2 * N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.minThrow(N, arr) << "\n";
    }
    return 0;
}  // } Driver Code Ends