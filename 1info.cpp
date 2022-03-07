#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;

int arr[100005] {};
vector<int> shoppingStore(int x, int n, vector<int>& items) {
	long long mx = 0, price = 0, sum = 0, l = 0, cnt = 0;

	for (int i = 0; i < n; i++) {
		if (arr[items[i]] > 0) {
			cnt++;
			arr[items[i]]++;
		} else if (sum + (long long)items[i] <= (long long)x) {
			cnt++;
			sum += (long long)items[i];
			arr[items[i]]++;
		} else {
			sum += (long long)items[i];
			arr[items[i]]++;
			cnt++;
			while (l <= i && sum > x) {
				if (arr[items[l]] > 1) {
					cnt--;
					arr[items[l]]--;
					l++;
				} else {
					cnt--;
					arr[items[l]]--;
					sum -= (long long)items[l];
					l++;
				}
			}
		}
		if (mx < cnt) {
			mx = cnt;
			price = sum;
		} else if (mx == cnt) {
			price = min(price, sum);
		}
	}

	vector<int> res = {mx, price};
	return res;
}

int solve(vector<int> a, int n, int k) {
	int mx1 = INT_MIN, mx2 = INT_MIN;
	if (n == 1) return (a[0] % MOD);
	for (auto ele : a) {
		if (ele >= mx1) {
			mx2 = mx1;
			mx1 = ele;
		} else if (mx2 < ele) {
			mx2 = ele;
		}
	}
	long long ans = 0, maxValue = 0;
	if (mx1 == mx2) {
		maxValue = (mx1 * k);
	} else {
		bool flag = false;
		// cout << mx1 << "   " << mx2 << endl;
		for (int i = 0; i < k; i++) {
			if (flag) {
				ans += mx2;
				flag = !flag;
			} else {
				ans += mx1;
				flag = !flag;
			}
			// cout << ans << "   ";
			if (ans > maxValue) maxValue = ans;
		}
	}
	return (maxValue % MOD);
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, k, mx1 = INT_MIN, mx2 = INT_MIN;
	cin >> n;
	vector<int> a;
	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		a.push_back(temp);
	}
	cin >> k;
	cout << solve(a, n, k);
	return 0;
}



vector<int> shoppingStore(int x, int n, vector<int>& items)
{
	vector<int> tr(n);
	vector<int> cost(n);

	int r = -1;
	int c = 0;
	int mx = 0;
	int price = 2e9;

	for (int l = 0; l < n; l++) {
		while (r < n - 1)
		{
			int new_cost = c;

			if (arr[items[r + 1]] == 0)
			{
				new_cost += items[r + 1];
			}

			if (new_cost <= x)
			{
				arr[items[r + 1]]++;
				r++;
				c = new_cost;
			}
			else
			{
				break;
			}

			tr[l] = r;
			cost[l] = c;
		}

		mx = max(mx, r - l + 1);
	}

	for (int l = 0; l < n; l++)
	{
		if (tr[l] - l + 1 == mx)
		{
			price = min(price, cost[l]);
		}
	}

	vector<int> res = {mx, price};

	return res;
}