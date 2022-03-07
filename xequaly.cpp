#include <bits/stdc++.h>

using namespace std;
// todo: do it again not completed
int permut(string a, int target, int curSum, int ind) {
    if (ind == a.size()) {
        if (curSum == target) return 1;
        else return 0;
    }
    int ans = 0;
    string sub = a.substr(ind);
    int n1 = stoi(sub);
    curSum += n1;
    ans += permut(a, target, curSum, ind+1);
    curSum -= n1;
    ans += permut(a, target, curSum, ind+1);
    return ans;
}
int minimum_pluses(string A){
    string a;
    string b;
    int i;
    for (i = 0; i<A.size(); i++) {
        if(A[i]=='=') break;
        a += A[i];
    }
    i++;
    for (;i<A.size();i++) b+=A[i];
    return permut(a, stoi(b), 0, 0);
}
int main(){
    string A;
    cin>>A;
    int result;
    result = minimum_pluses(A);
    cout<<result;
    return 0;
}