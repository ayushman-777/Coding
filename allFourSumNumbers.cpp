// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required

    /*void fourSumUtil(vector<int> &arr, int k, int ind, vector<int> &temp, set<vector<int>> &ans) {
        if (temp.size() == 4) {
            int sum = 0;
            for (auto ele : temp) sum += ele;
            if (sum == k) ans.insert(temp);
            return;
        }

        if (ind == arr.size()) return;

        fourSumUtil(arr, k, ind + 1, temp, ans);

        temp.push_back(arr[ind]);

        fourSumUtil(arr, k, ind + 1, temp, ans);
        temp.pop_back();

    }
    vector<vector<int>> fourSum(vector<int> &arr, int k) {
        vector<vector<int>> ans;
        set<vector<int>> tempAns;
        vector<int> temp;
        sort(arr.begin(), arr.end());

        fourSumUtil(arr, k, 0, temp, tempAns);

        for (auto ele : tempAns) ans.push_back(ele);
        return ans;
    }*/

    vector<vector<int>> fourSum(vector<int> &arr, int k) {
        int n = arr.size(), start, end;
        sort(arr.begin(), arr.end());
        set<vector<int>> ans;
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                start = j + 1;
                end = n - 1;
                while (start < end) {
                    if (arr[i] + arr[j] + arr[start] + arr[end] == k) {
                        ans.insert({arr[i], arr[j], arr[start], arr[end]});
                        start++;
                        end--;
                    } else if (arr[i] + arr[j] + arr[start] + arr[end] < k) {
                        start++;
                    } else {
                        end--;
                    }
                }
            }
        }
        vector<vector<int>> result;
        for (auto ele : ans) {
            result.push_back(ele);
        }
        return result;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends