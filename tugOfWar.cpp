#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> &vec, int ind, int elements_selected, int sum, vector<bool> &sol, vector<bool> &curSol, int curSum, int &minSum) {
    if (ind == vec.size()) return;

    if (((vec.size() / 2) - elements_selected) > (vec.size() - ind)) return;

    solve(vec, ind + 1, elements_selected, sum, sol, curSol, curSum, minSum);

    elements_selected++;
    curSol[ind] = true;
    curSum += vec[ind];

    if (elements_selected == (vec.size() / 2)) {
        if (abs(sum / 2 - curSum) <= minSum) {
            minSum = abs(sum / 2 - curSum);
            for (int i = 0; i < sol.size(); i++) {
                sol[i] = curSol[i];
            }
        }
    } else {
        solve(vec, ind + 1, elements_selected, sum, sol, curSol, curSum, minSum);
    }

    curSol[ind] = false;

}
int main() {

    int n; cin >> n;
    vector<int> vec(n);
    vector<bool> sol(n);
    vector<bool> curSol(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        sum += temp;
        vec[i] = temp;
        sol[i] = curSol[i] = false;
    }
    int minDiff = INT_MAX;
    solve(vec, 0, 0, sum, sol, curSol, 0, minDiff);
    for (int i = 0; i < n; i++) {
        if (sol[i]) {
            cout << vec[i] << "   ";
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        if (!sol[i]) {
            cout << vec[i] << "   ";
        }
    }
    return 0;
}