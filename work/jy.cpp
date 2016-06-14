#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e5 + 12;
typedef long long ll;
int T, k;
ll n, dp[20][200];
int bits[20];


ll dfs(int len, int sum, bool limit, int th, ll ans, bool zero) {
    if (len == 0) {return  sum == 0 ? ans : 0;}
    if (!limit && dp[len][sum + 100] != -1) { return dp[len][sum + 100];}

    int m = limit ? bits[len] : 9;

    ll ret = 0;
    for (int i = 0; i <= m; i++) {
        if (i) zero = true; 
        if (th % 2) ret += dfs(len - 1, sum - i, limit && i == m, zero ? th + 1 : th, ans * 10 + i, zero);
        else ret += dfs(len - 1, sum + i, limit && i == m, zero ? th + 1 : th, ans * 10 + i, zero);
    }

    if (!limit) dp[len][sum + 100] = ret % mod;
    return ret % mod;
}

ll solve(ll n) {
    ll key = n, t = 1;
    while (key) {
        bits[t++] = key % 10;
        cout << bits[t - 1];
        key /= 10;
    }
    cout << endl;
    return dfs(t - 1, k, true, 1, 0, false);
}


int main(void)
{
#ifdef LOCAL
     freopen("in.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
#endif
    ll l, r;
    while (cin >> l >> r >> k) {
        memset(dp, -1, sizeof(dp));
        ll rs = solve(r);
        memset(dp, -1, sizeof(dp));
        ll ls = solve(l - 1);
        cout << (rs - ls + mod) % mod << endl;
    }
    return 0;
}
