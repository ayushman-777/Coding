#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    void fillStack(string s, stack<pair<char, int>> &st) {
        for (int i = 0; i < s.length(); i++) {
            if (st.empty() && (s[i] == '(' || s[i] == ')')) {
                st.push({s[i], i});
            } else if (s[i] == ')' && st.top().first == '(') {
                st.pop();
            } else if (s[i] == '(' || s[i] == ')') {
                st.push({s[i], i});
            }
        }
    }
    void removeUtil(string s, stack<pair<char, int>> st, int ind, unordered_set<string> &ans, vector<int> &toErase) {
        if (ind == 0 || st.empty()) {
            // cout << s << "  " << st.size() << endl;
            if (st.empty()) {
                for (auto ele : toErase) s.erase(ele, 1);
                ans.insert(s);
            }
            return;
        }

        pair<char, int> temp = st.top();

        if (s[ind] == '(') {
            if (temp.first == '(' && temp.second <= ind) {
                toErase.push_back(ind);
                st.pop();
                removeUtil(s, st, ind - 1, ans, toErase);
                st.push(temp);
                toErase.pop_back();
            }
        } else if (s[ind] == ')') {
            if (temp.first == ')' && temp.second >= ind) {
                toErase.push_back(ind);
                st.pop();
                removeUtil(s, st, ind - 1, ans, toErase);
                st.push(temp);
                toErase.pop_back();
            }
        }

        removeUtil(s, st, ind - 1, ans, toErase);
    }
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> vec;
        vector<string> ans;
        stack<pair<char, int>> st;
        fillStack(s, st);
        vector<int> toErase;
        removeUtil(s, st, s.length() - 1, vec, toErase);
        for (auto ele : vec) {
            ans.push_back(ele);
        }

        return ans;
    }
};

int main() {
    int t; cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution sol;
        vector<string> ans;
        ans = sol.removeInvalidParentheses(s);

        for (auto ele : ans) {
            cout << ele << endl;
        }
        cout << endl;
    }
    return 0;
}