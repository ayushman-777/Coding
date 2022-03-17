// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	void helper(string s, set<string> &ans, int l, int r) {

		if (l == r) {
			ans.insert(s);
		} else {
			for (int i = 0; i <= r; i++) {
				swap(s[l], s[i]);
				helper(s, ans, l + 1, r);
				swap(s[l], s[i]);
			}
		}
	}
	vector<string>find_permutation(string S)
	{
		set<string> ans;
		vector<string> res;
		helper(S, ans, 0, S.size() - 1);
		for (auto ele : ans) {
			res.push_back(ele);
		}
		return res;
	}
};



// { Driver Code Starts.
int main() {
	int t;
	cin >> t;
	while (t--)
	{
		string S;
		cin >> S;
		Solution ob;
		vector<string> ans = ob.find_permutation(S);
		for (auto i : ans)
		{
			cout << i << " ";
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends