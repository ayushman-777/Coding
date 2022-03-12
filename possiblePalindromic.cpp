// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void dfs(vector<string> &s, set<vector<string>> &ans, int ind) {
        if (ind == s.size()) {
            ans.insert(s);
            return;
        }
        if (ind + 1 < s.size() && s[ind] == s[ind + 1]) {
            vector<string> temp;
            for (int i = 0; i < s.size(); i++) {
                if (i == ind) {
                    string sTemp;
                    sTemp += s[i] + s[i + 1];
                    temp.push_back(sTemp);
                    i++;
                } else {
                    string sTemp;
                    sTemp += s[i];
                    temp.push_back(sTemp);
                }
            }
            ans.insert(temp);
            dfs(temp, ans, 0);
        }
        if (ind + 2 < s.size() && s[ind] == s[ind + 2]) {
            vector<string> temp;
            for (int i = 0; i < s.size(); i++) {
                if (i == ind) {
                    string sTemp;
                    sTemp += s[i] + s[i + 1] + s[i + 2];
                    temp.push_back(sTemp);
                    i += 2;
                } else {
                    string sTemp;
                    sTemp += s[i];
                    temp.push_back(sTemp);
                }
            }
            ans.insert(temp);
            dfs(temp, ans, 0);
        }
        dfs(s, ans, ind + 1);
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        set<vector<string>> se;
        vector<vector<string>> ans;
        vector<string> st;
        for (int i = 0; i < S.size(); i++) {
            string st1;
            st1 += S[i];
            st.push_back(st1);
        }
        dfs(st, se, 0);
        for (auto ele : se) {
            ans.push_back(ele);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;

        cin >> S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);

        for (int i = 0; i < ptr.size(); i++)
        {
            for (int j = 0; j < ptr[i].size(); j++)
            {
                cout << ptr[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}  // } Driver Code Ends