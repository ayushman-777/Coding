// PRIORITY QUEUE is !IMPORTANT

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char , int> mp;
        priority_queue<pair<int , char>> pq;

        for (int i = 0; i < s.size(); i++)
            mp[s[i]]++;

        for (auto it = mp.begin(); it != mp.end(); it++)
            pq.push({it->second , it->first});

        string ans = "";

        while (!pq.empty())
        {
            int x = pq.top().first;
            char cx = pq.top().second;
            pq.pop();

            if (!ans.empty() && ans[ans.size() - 1] == cx) return "";

            ans.push_back(cx);
            x--;

            if (!pq.empty()) {
                int y = pq.top().first;
                char cy = pq.top().second;
                pq.pop();
                ans.push_back(cy);
                y--;

                if (y != 0) pq.push({y , cy});
            }

            if (x != 0) pq.push({x , cx});
        }
        return ans;
    }
};

int main() {
    return 0;
}