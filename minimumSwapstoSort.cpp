// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
    	void swap(vector<int> &nums, int i, int j) {
    		int temp = nums[i];
    		nums[i] = nums[j];
    		nums[j] = temp;
    	}

    int indexOf(vector<int> &nums, int ele) {
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		if (nums[i] == ele) return i;
    	}
    	return -1;
    }

	int minSwaps(vector<int>&nums)
	{
	    vector<int> temp(nums.begin(), nums.end());
	    sort(temp.begin(), temp.end());

	    int n = nums.size(), ans = 0;
	    unordered_map<int, int> mp;
	    for (int i = 0; i < n; i++) mp[nums[i]] = i;

	    for (int i = 0; i < n; ++i)
	    {
	    	if(temp[i] != nums[i]) {
	    		ans++;
	    		int ind = nums[i];
	    		swap(nums, i, mp[temp[i]]);
	    		mp[ind] = mp[temp[i]];
	    		mp[temp[i]] = i;
	    	}
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends