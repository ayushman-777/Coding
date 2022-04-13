#include "bits/stdc++.h"

using namespace std;
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;

void splitString(string &s, vector<string> &ans) {
	string word = "";
	for (auto ch : s) {
		if (ch == ' ') {
			ans.push_back(word);
			word = "";
		} else {
			word += ch;
		}
	}
	ans.push_back(word);
}
pair<int, int> tableValue(char s) {
	pair<int, int> p;
	int val = -1;
	if (s == '0') {
		val = 0;
		p = make_pair(val, val + 2);
	} else if (s >= 65 && s <= 90) {
		val = s - 55;
		p = make_pair(val, val + 1);
	} else if (s >= 97 && s <= 122) {
		val = s - 61;
		p = make_pair(val, val + 1);
	} else if (s >= 48 && s <= 57) {
		val = s - 48;
		p = make_pair(val, val + 1);
	}
	return p;
}

int calReactivity(string s) {
	int ans = 0, carry = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		pair<int, int> temp = tableValue(s[i]);
		if ((unsigned)i == s.size() - 1) {
			carry = temp.second;
			ans += temp.first;
		}
		else ans += (temp.first * carry);
	}
	return ans;
}

void allPermute(vector<string> &allString, int &ans, pair<string, string> temp, int ind) {
	if ((unsigned)ind == allString.size()) {
		return;
	}
	if (temp.second != "") {
		int reactivity1 = calReactivity(temp.first), reativity2 = calReactivity(temp.second);
		// cout << temp.first << "   " << temp.second << endl;
		// cout << reactivity1 << "   " << reativity2 << endl;
		ans = max(ans, __gcd(reactivity1, reativity2));
		return;
	}
	for (int i = ind; (unsigned)i < allString.size() - 1; i++) {
		allPermute(allString, ans, temp, ind + 1);
		temp.first = allString[i];
		for (int j = i + 1; (unsigned)j < allString.size(); j++) {
			temp.second = allString[j];
			allPermute(allString, ans, temp, ind);
		}
	}
}

void solve() {
	string s;
	getline(cin, s);
	vector<string> allString;
	splitString(s, allString);

	int ans = 0;
	// for (auto ele : allString) {
	// 	cout << ele << "  ";
	// }
	pair<string, string> temp;
	allPermute(allString, ans, temp, 0);
	cout << ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	solve();

	return 0;
}
