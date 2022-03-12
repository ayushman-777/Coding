// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    // TLE
    bool allSubsets(int arr[], int l, int r, int req, int sum = 0) {
        if (l > r) {
            if ((req - sum) == sum) return true;
            return false;
        }

        if (allSubsets(arr, l + 1, r, req, sum + arr[l])) return true;

        if (allSubsets(arr, l + 1, r, req, sum)) return true;

        return false;
    }
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += arr[i];
        }
        if (allSubsets(arr, 0, N - 1, sum)) {
            return 1;
        }
        return 0;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}  // } Driver Code Ends