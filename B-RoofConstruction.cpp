#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

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

int mini = INT_MAX;
vector<int> minAns;

bool cost(vector<int> vector1) {
    int ans = 0;
    for (int i = 0; i < vector1.size() - 1; ++i) {
        ans = max(ans, (vector1[i] ^ vector1[i + 1]));
        if (ans>mini) break;
    }
    if(ans < mini) {
        mini = ans;
        return true;
    }
    return false;
}

void permutation(vector<int> seq, vector<int> answer) {
    if (seq.size() == 0) {
        if(cost(answer)) {
            minAns = answer;
        }
        return;
    }
    for (int i = 0; i < seq.size(); ++i) {
        int ch = seq[i];
        vector<int> rest;
        for (auto ele: seq) if (ele != ch) rest.emplace_back(ele);
        answer.emplace_back(ch);
        permutation(rest, answer);
        answer.pop_back();
    }
}

void solve() {
    /*int n;
    cin>>n;
    vector<int> s;
    for (int i = 0; i < n; ++i)
    {
    	s.emplace_back(i);
    }
    mini = INT_MAX;
    vector<int> ans;
    permutation(s, ans);
    for (auto ele: minAns) cout << ele << " ";
    cout << endl;*/
    ll n; 
    cin >> n;
    ll k=1LL;
    n--;
    
    while(2*k<=n) k=k*2;

    for(ll i=n;i>=k;i--) cout<<i<<" ";

    for(ll i=0;i<k;i++) cout<<i<<" ";

    cout<<endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
 	
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
 
	return 0;
}
