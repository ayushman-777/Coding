// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	/*int util(int n, int arr[]) {
		if (n == 1) return 1;
		if (n == 2) return 2;

		int l = arr[n - 1] == -1 ? util(n - 1, arr) : arr[n - 1];
		int r = arr[n - 2] == -1 ? util(n - 2, arr) : arr[n - 2];
		return (l + r) % 1000000007;
	}
	int nthPoint(int n) {
		int arr[n + 1];
		memset(arr, -1, sizeof(arr));
		return util(n, arr);
	}*/
	int nthPoint(int n) {
		int arr[n + 1];
		memset(arr, -1, sizeof(arr));
		return util(n, arr);
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends