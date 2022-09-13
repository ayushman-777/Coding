/*#include "bits/stdc++.h"
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

void helper(vector<string> &vec, unordered_set<string> &ans, int l, int r) {
	cout << l << "   " << r << endl;
	if (l == r) {
		string temp;
		for (auto ele : vec) {
			temp += ele;
			cout << temp << "  ";
		}
		cout << endl;
		ans.insert(temp);
		return;
	} else {
		for (int i = 0; i <= r; i++) {
			swap(vec[l], vec[i]);
			helper(vec, ans, l + 1, r);
			swap(vec[l], vec[i]);
		}
	}
}

void solve() {
	int n;
	cin >> n;
	vector<string> vec;
	int arr[n + 1];
	for (int i = 1; i <= n; i++) {
		vec.push_back(to_string(i));
		arr[i] = i;
	}

	// for (auto ele : vec) cout << ele << "   ";

	unordered_set<string> st;

	helper(vec, st, 0, vec.size() - 1);

	for (auto ele : st) cout << ele << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	solve();

	return 0;
}*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;

int addWithMod(long long a, long long b) {
	return ((a % MOD) + (b % MOD)) % MOD;
}

int multiplyWithMod(long long a, long long b) {
	return ((a % MOD) * 1LL * (b % MOD)) % MOD;
}

int binaryPower(long long a, long long b) {
	a %= MOD;
	long long res = 1;
	while (b > 0) {
		if (b & 1) {
			res = res * 1LL * a % MOD;
		}
		a = a * 1LL * a % MOD;
		b = b >> 1;
	}
	return res;
}

int reverse(long long x)
{
	cout << binaryPower(x, MOD - 2) << endl;
	return binaryPower(x, MOD - 2);
}

int numberOfPermutations(long long n, long long k)
{
	k = n - k;

	int ans = 1;

	if (k == 0 or k == 1) {
		return ans;
	}

	ans += multiplyWithMod(multiplyWithMod(n, n - 1), reverse(2));
	cout << reverse(2) << endl;
	if (k == 2) {
		return ans;
	}

	ans += multiplyWithMod(multiplyWithMod(n, multiplyWithMod(n - 1, n - 2)), reverse(3));

	if (k == 3) {
		return ans;
	}

	int u = multiplyWithMod(n, multiplyWithMod(n - 1, multiplyWithMod(n - 2, n - 3)));
	ans = addWithMod(ans, multiplyWithMod(u, reverse(8)));
	ans = addWithMod(ans, multiplyWithMod(u, reverse(4)));

	return ans;
}

void solve() {
	int n;
	cin >> n;
	cout << numberOfPermutations(n, 1LL);
}

int main()
{
	solve();
	return 0;
}
