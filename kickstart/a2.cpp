#include "bits/stdc++.h"

using namespace std;
#define endl '\n'

void computeLPSArray(vector<int> &pat, int M, int* lps) {
  int len = 0;

  lps[0] = 0;

  int i = 1;
  while (i < M) {
    if (pat[i] == pat[len]) {
      len++;
      lps[i] = len;
      i++;
    }
    else {
      if (len != 0) {
        len = lps[len - 1];
      }
      else {
        lps[i] = 0;
        i++;
      }
    }
  }
}

bool search(vector<int> &pat, vector<int> &txt) {
  int M = pat.size();
  int N = txt.size();
  int lps[M];
  computeLPSArray(pat, M, lps);

  int i = 0;
  int j = 0;
  while ((N - i) >= (M - j)) {
    if (pat[j] == txt[i]) {
      j++;
      i++;
    }

    if (j == M) {
      return false;
      j = lps[j - 1];
    }
    else if (i < N && pat[j] != txt[i]) {
      if (j != 0)
        j = lps[j - 1];
      else
        i = i + 1;
    }
  }
  return true;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n), c;
  unordered_set<int> st;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    st.insert(a[i]);
    c.push_back(a[i]);
  }
  for (int i = 0; i < n; i++) {
    c.push_back(a[i]);
    cin >> b[i];
  }
  if (st.size() == 1) {
    cout << "YES" << endl;
    return;
  }
  bool notMactch = search(b, c);

  bool flag = false;
  if (a == b) flag = true;
  if (notMactch) {
    cout << "NO" << endl;
  } else if (!flag && k == 0) {
    cout << "NO" << endl;
  } else if (flag && k == 1) {
    cout << "NO" << endl;
  } else if (!flag && a.size() == 2 && (k & 1) == 0) { // even
    cout << "NO" << endl;
  } else if (flag && a.size() == 2 && (k & 1)) {
    cout << "NO" << endl;
  } else cout << "YES" << endl;
}

int main() {
  int T = 1;
  cin >> T;
  int ind = 1;
  while (T--) {
    cout << "Case #" << ind << ": ";
    ind++;
    solve();
  }
  return 0;
}
