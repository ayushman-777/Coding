// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
public:
    //Function to return a list of indexes denoting the required
    //combinations whose sum is equal to given number.
    /*    void findNumbers(vector<int>& ar, int sum,
                     vector<vector<int> >& res, vector<int>& r,
                     int i)
    {
        // if we get exact answer
        if (sum == 0) {
            res.push_back(r);
            return;
        }

        // Recur for all remaining elements that
        // have value smaller than sum.
        while (i < ar.size() && sum - ar[i] >= 0) {

            // Till every element in the array starting
            // from i which can contribute to the sum
            r.push_back(ar[i]); // add them to list

            // recur for next numbers
            findNumbers(ar, sum - ar[i], res, r, i);
            i++;

            // Remove number from list (backtracking)
            r.pop_back();
        }
    }

    // Returns all combinations
    // of ar[] that have given
    // sum.
    vector<vector<int> > combinationSum(vector<int>& ar,
                                        int sum)
    {
        // sort input array
        sort(ar.begin(), ar.end());

        // remove duplicates
        ar.erase(unique(ar.begin(), ar.end()), ar.end());

        vector<int> r;
        vector<vector<int> > res;
        findNumbers(ar, sum, res, r, 0);

        return res;
    }*/

    /*void solve(vector<int> &a, set<vector<int>> &ans,
                   int b, int ind, vector<int> &selected,
                   int selectedSum) {
            // cout << ind << "  " << selectedSum << endl;
            if (selectedSum == b) {
                ans.insert(selected);
                return;
            }

            if (selectedSum > b || ind == a.size() || a[ind] > b) return;

            solve(a, ans, b, ind + 1, selected, selectedSum);

            selected.push_back(a[ind]);
            selectedSum += a[ind];

            solve(a, ans, b, ind, selected, selectedSum);
            solve(a, ans, b, ind + 1, selected, selectedSum);

            selectedSum -= a[ind];
            selected.pop_back();
        }
        vector<vector<int>> combinationSum(vector<int> &A, int B) {
            set<vector<int>> ans;
            vector<vector<int>> res;
            vector<int> temp;
            sort(A.begin(), A.end());
            A.erase(unique(A.begin(), A.end()), A.end());
            solve(A, ans, B, 0, temp, 0);
            for (auto ele : ans) res.push_back(ele);
            return res;
        }*/

    void findNumbers(vector<int>& a, int sum,
                     vector<vector<int>>& res, vector<int>& r,
                     int ind) {
        if (sum == 0) {
            res.push_back(r);
            return;
        }
        while (ind < a.size() && sum - a[ind] >= 0) {
            r.push_back(a[ind]);
            findNumbers(a, sum - a[ind], res, r, ind);
            ind++;
            r.pop_back();
        }
    }

    vector<vector<int> > combinationSum(vector<int>& ar,
                                        int sum) {
        sort(ar.begin(), ar.end());

        ar.erase(unique(ar.begin(), ar.end()), ar.end());

        vector<int> r;
        vector<vector<int> > res;
        findNumbers(ar, sum, res, r, 0);

        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            A.push_back(x);
        }
        int sum;
        cin >> sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
        if (result.size() == 0) {
            cout << "Empty";
        }
        for (int i = 0; i < result.size(); i++) {
            cout << '(';
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j];
                if (j < result[i].size() - 1)
                    cout << " ";
            }
            cout << ")";
        }
        cout << "\n";
    }
}     // } Driver Code Ends