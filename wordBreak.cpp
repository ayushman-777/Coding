// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    bool wordBreakUtil(string a, unordered_set<string> &b, int ind) {
        if (ind == a.size()) return true;

        for (int i = ind+1; i <= a.size(); ++i) {
            cout << a.substr(ind, i-ind) << endl;
            if (b.find(a.substr(ind, i-ind)) != b.end() and
                wordBreakUtil(a, b, i))
                    return true;
        }
        return false;
    }

    int wordBreak(string A, vector<string> &B) {
        unordered_set<string> b(B.begin(), B.end());
        return wordBreakUtil(A, b, 0);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends