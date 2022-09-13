//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        sort(a, a + n);
        long long int ans = 0;
        bool zero = false;
        int ind;
        for (ind = 0; ind < n && k > 0; ind++) {
            if (a[ind] == zero) zero = true;
            if (a[ind] >= 0) break;
            a[ind] = -a[ind];
            k--;
        }
        if (k == 0 || k % 2 == 0 || zero) {
            for (int i = 0; i < n; i++) {
                ans += a[i];
            }
        } else {
            // for (int i = 0; i < n; i++) cout << a[i] << " ";
            if (ind > 0) --ind;
            a[ind] = -a[ind];
            for (int i = 0; i < n; i++) ans += a[i];
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
        int n, k;
        cin >> n >> k;
        long long int a[n + 5];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.maximizeSum(a, n, k) << endl;
    }

    return 0;
}
// } Driver Code Ends