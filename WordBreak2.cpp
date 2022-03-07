// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    void wordBreakUtil(unordered_set<string> &us, string s, int ind, int n, vector<string> &ans, string &res) {
        if (ind >= s.size()) {
            // cout << s << endl;
            if (us.find(s) != us.end()) {
                ans.push_back(res + s);
            }
            return;
        }

        string sub = s.substr(0, ind);
        // cout << sub << endl << s << endl << endl;

        if (us.find(sub) != us.end()) {
            res += sub;
            res += " ";
            wordBreakUtil(us, s.substr(ind), 0, n, ans, res);
            res.pop_back();
            for (auto ele : sub) res.pop_back();
        }

        wordBreakUtil(us, s, ind + 1, n, ans, res);
    }

    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        unordered_set<string> us(dict.begin(), dict.end());
        vector<string> ans;
        string res;
        wordBreakUtil(us, s, 0, s.length(), ans, res);
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<string> dict;
        string s;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s;
            dict.push_back(s);
        }
        cin >> s;

        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if (ans.size() == 0)
            cout << "Empty\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
                cout << "(" << ans[i] << ")";
            cout << endl;
        }
    }
    return 0;
}  // } Driver Code Ends