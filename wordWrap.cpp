// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
int solve(vector<int>&nums,int k,int k1,int n,int i){
       if(i==n-1){
           if(k1>nums[i])
            return 0;
           else
            return k1*k1;
       }
       if(k1==k){
           return solve(nums,k,k-nums[i],n,i+1);
       }
        if(k1>nums[i])
            return min(k1*k1+solve(nums,k,k,n,i),solve(nums,k,k1-1-nums[i],n,i+1));
        else
            return k1*k1+solve(nums,k,k,n,i);
   }

   int solveWordWrap(vector<int>nums, int k) 
   {
       int n=nums.size();
       return solve(nums,k,k,n,0);
   }
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n;
		vector<int>nums(n);
		for (int i = 0; i < n; i++)cin >> nums[i];
		cin >> k;
		Solution obj;
		cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends