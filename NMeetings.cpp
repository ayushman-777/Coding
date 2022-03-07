// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        multimap<int, int> mp;
        for (int i = 0; i<n; i++) mp.insert({end[i], start[i]});
        auto it1 = mp.begin();
        auto it = mp.begin();
        int e = it->first, count = 1;
        for (auto ele: mp) cout << ele.second << " # " << ele.first << endl;
        for (it++; it != mp.end(); it++) {
            if (it->second > e) {
                count++;
                e = it->first;
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends