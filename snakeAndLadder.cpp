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

void splitString(string &s, vector<string> &ans) {
	string word = "";
	for (auto ch : s) {
		if (ch == ' ') {
			ans.emplace_back(word);
			word = "";
		} else {
			word += ch;
		}
	}
	ans.emplace_back(word);
}

void solve() {
	vector<string> board;
	string s;
	int count = 0;
	vector<string> inst;
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) {
			getline(cin, s);
			splitString(s, board);
		} else {
			getline(cin, s);
			vector<string> temp;
			splitString(s, temp);
			reverse(temp.begin(), temp.end());
			for (auto ele : temp) board.push_back(ele);
		}
	}
	getline(cin, s);
	splitString(s, inst);
	reverse(board.begin(), board.end());
	board[0] = "1";
	board[board.size() - 1] = "100";
	// for (auto ele : board) cout << ele << "  ";
	int ind = -1, countS = 0, countL = 0;
	bool flag = false;
	for (auto ele : inst) {
		int temp = stoi(ele);
		// cout << temp << "   " << ind << endl;;
		if (ind + temp > 99) {
			continue;
		} else if (board[ind + temp] == "100") {
			flag = true;
			break;
		} else if (board[ind + temp].substr(0, 1) == "S") {
			if (board[ind + temp].find("Start") != string::npos) {
				ind = -1;
			} else {
				int temp1 = stoi(board[ind + temp].substr(2, board[ind + temp].size() - 3));
				ind = temp1 - 1;
			}
			countS++;
		}  else if (board[ind + temp].substr(0, 1) == "L") {
			if (board[ind + temp].find("End") != string::npos) {
				flag = true;
				countL++;
				break;
			} else {
				int temp1 = stoi(board[ind + temp].substr(2, board[ind + temp].size() - 3));
				ind = temp1 - 1;
			}
			countL++;
		} else {
			ind += temp;
		}
	}

	if (flag) {
		cout << "Possible  " << countL << "  " << countS << endl;
	} else {
		cout << "Not Possible" << endl;
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	solve();

	return 0;
}
