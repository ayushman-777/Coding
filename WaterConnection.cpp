// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d)
    {
        vector<vector<int>> ans;
        vector<int> sOnly;

        map<int, int> A;
        map<int, int> B;
        for (int i = 0; i < p; i++) {
            A.insert({a[i], i});
            B.insert({b[i], i});
        }

        for (int i = 0; i < p; i++) {
            if (B.find(a[i]) == B.end()) {
                sOnly.push_back(a[i]);
            }
        }

        sort(sOnly.begin(), sOnly.end());

        for (int i = 0; i < sOnly.size(); i++) {
            int source = sOnly[i];
            int minimum = INT_MAX;
            int destination = -1;
            int tempSource = source;
            while (A.find(tempSource) != A.end()) {
                minimum = min(minimum,  d[A[tempSource]]);
                tempSource = b[A[tempSource]];
                destination = tempSource;
            }
            ans.push_back({source, destination, minimum});
        }

        return ans;
    }
};


// { Driver Code Starts.
int main()
{
    int t, n, p;
    cin >> t;
    while (t--)
    {
        cin >> n >> p;
        vector<int> a(p), b(p), d(p);
        for (int i = 0; i < p; i++) {
            cin >> a[i] >> b[i] >> d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n, p, a, b, d);
        cout << answer.size() << endl;
        for (auto i : answer)
        {
            cout << i[0] << " " << i[1] << " " << i[2] << endl;
        }

    }
    return 0;
}  // } Driver Code Ends