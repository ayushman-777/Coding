// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
		multimap<int, int> mp; // ending time, starting time
		vector<vector<int>> res;
		for (auto inter : intervals) {
			mp.insert({inter[0], inter[1]}); // O(n*log(n))
		}
		vector<int> prev(2);
		for (auto ele : mp) {
			// cout << ele.first << "   " << ele.second << endl;
			if (res.size() == 0) { // O(n)
				prev[0] = ele.first;
				prev[1] = ele.second;
				res.push_back(prev);
				continue;
			}
			if (res[res.size() - 1][1] >= ele.first) {
				res[res.size() - 1][1] = max(ele.second, res[res.size() - 1][1]);
				res[res.size() - 1][0] = min(ele.first, res[res.size() - 1][0]);
			} else {
				prev[0] = ele.first;
				prev[1] = ele.second;
				res.push_back(prev);
			}
		}
		return res;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for (auto i : ans) {
			for (auto j : i) {
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends