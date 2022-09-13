#include "bits/stdc++.h"

using namespace std;

void solve() {
    int m;
    cin >> m;
    int q;
    cin >> q;
    vector<int> a;
    int temp, tempai, xr = 0;
    while (q--) {
        cin >> temp;
        if (temp == 1) {
            cin >> tempai;
            xr ^= tempai;
            a.push_back(tempai);
        } else if (temp == 2) {
            xr ^= a[a.size() - 1];
            a.pop_back();
        } else {
            // for (auto ele : a) cout << ele << "  ";
            int ans = 0, maxi = 0;
            for (int i = 2 * m; i > 0; i--) {
                if (ans < (xr ^ i)) {
                    ans = (xr ^ i);
                    maxi = i;
                }
            }
            cout << maxi << endl;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cout.tie(0);

    solve();

    return 0;
}
