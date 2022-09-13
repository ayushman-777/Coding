//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
public:
	int MOD = 1000000007;
	long long int findMaxProduct(vector<int>&a, int n) {
		if (n == 1) return a[0];
		long long int cntN = 0, ansN = 1, cntP = 0, ansP = 1, cntZ = 0;
		int maxi = INT_MIN;
		for (auto &ele : a) {
			if (ele == 0) cntZ++;
			else if (ele < 0) cntN++, ansN = (ansN * ele * 1ll) % MOD, maxi = max(maxi, ele);
			else cntP++, ansP = (ansP * ele * 1ll) % MOD;
		}
		if (cntP == 0 && cntN == 1 && cntZ > 0) return 0;
		long long int ans = ansP;
		if (cntN % 2 == 0) {
			ans = (ans * ansN * 1ll) % MOD;
		} else {
			ansN /= maxi;
			ans = (ans * ansN * 1ll) % MOD;
		}
		return ans;
	}
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int>arr(n);
		for (int i = 0 ; i < n; i++) {
			cin >> arr[i];
		}
		Solution ob;
		long long int ans = ob.findMaxProduct(arr, n);
		cout << ans << endl;
	}
	return 0;
}

// } Driver Code Ends