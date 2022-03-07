// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        multimap<double, pair<int, int>> mp;
        double wt, val;
        for (int i = 0; i < n; i++) {
            wt = arr[i].weight;
            val = arr[i].value;
            double weVal = wt / val;
            mp.insert({weVal, {val, wt}});
        }
        double ans = 0, curWt = 0;
        for (auto ele : mp) {
            if (curWt + ele.second.second <= W) {
                ans += ele.second.first;
                curWt += ele.second.second;
            } else {
                int remain = W - curWt;
                ans += ele.second.first * ((double)remain / (double)ele.second.second);
                break;
            }
        }
        return ans;
    }

};


// { Driver Code Starts.
int main()
{
    int t;
    //taking testcases
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--) {
        //size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        //value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        //function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}  // } Driver Code Ends