// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// Continuous subarray maximum sum with k blocks
// 1 2 3 1 4 5 2 3 6, k=3
// left -> 1 2 3 1 4 5 2 3 6
//right -> 3 3 3 5 5 5 6 6 6
// ans  -> 3 3 4 5 5 5 6

// } Driver Code Ends
class Solution {
public:
   vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
      // multimap<int, int> s; // {value, position}
      // vector<int> res;
      // for (int i = 0; i < n; i++) {
      //    s.insert({arr[i], i});
      // }
      // for (int i = 0; i <= n - k; i++) {
      //    for (auto it = s.rbegin(); it != s.rend(); it++) {
      //       if ( (*it).second >= i && (*it).second < (i + k)) {
      //          res.push_back((*it).first);
      //          break;
      //       }
      //    }
      // }
      // return res;

      if (k == 1) {
         return arr;
      }

      vector<int> left(n), right(n), ans;

      for (int i = 0; i < n; i++) {
         if (i % k == 0) left[i] = arr[i];
         else left[i] = max(left[i - 1], arr[i]);

         if ((n - i) % k == 0 || i == 0) right[n - 1 - i] = arr[n - 1 - i];
         else right[n - 1 - i] = max(right[n - i], arr[n - 1 - i]);
      }
      for (int i = 0, j = k - 1; j < n; i++, j++)
         ans.push_back(max(right[i], left[j]));
      return ans;
   }
};

// { Driver Code Starts.

int main() {

   int t;
   cin >> t;

   while (t--) {

      int n, k;
      cin >> n >> k;

      vector<int> arr(n);
      for (int i = 0; i < n; i++) cin >> arr[i];
      Solution ob;
      vector<int> res = ob.max_of_subarrays(arr, n, k);
      for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
      cout << endl;
   }

   return 0;
}  // } Driver Code Ends