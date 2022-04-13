// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
public:
    int *findTwoElement(int *arr, int n) {
        int *ans = new int[2];
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            if (st.find(arr[i]) == st.end()) {
                st.insert(arr[i]);
            } else {
                ans[1] = i + 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (st.find(i) != st.end()) {
                ans[0] = i;
                break;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends