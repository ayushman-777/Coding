#include "bits/stdc++.h"
using namespace std;

void permute(string a, int l, int r, vector<string> &permut)
{
    // Base case
    if (l == r) {
        permut.push_back(a);
    }
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {

            // Swapping done
            swap(a[l], a[i]);

            // Recursion called
            permute(a, l + 1, r, permut);

            //backtrack
            swap(a[l], a[i]);
        }
    }
}

int isNumber(string s) {
    if (s == "nine") return 9;
    else if (s == "eight") return 8;
    else if (s == "seven") return 7;
    else if (s == "six") return 6;
    else if (s == "five") return 5;
    else if (s == "four") return 4;
    else if (s == "three") return 3;
    else if (s == "two") return 2;
    else if (s == "one") return 1;
    else if (s == "zero") return 0;
    else return -1;
}
void subString(string s, unordered_set<int> &st)
{
    int n = s.length();
    for (int i = 0; i < n; i++)
        for (int len = 1; len <= n - i; len++) {
            int num = isNumber(s.substr(i, len));
            if (num != -1) {
                st.insert(num);
            }
        }
}
int main() {

    string s;
    cin >> s;
    vector<string> permut;
    permute(s, 0, s.length() - 1, permut);
    unordered_set<int> st;
    for (auto ele : permut) {
        subString(ele, st);
    }
    for (auto ele : st) cout << ele << endl;
    return 0;
}


// Input To Test
// inneght
// frneniro
// oentrheni
