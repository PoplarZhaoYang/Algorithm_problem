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
int bits[20];
ll base[20];

struct node {
    ll sum, cnt;
}dp[20][20][400];

node dfs(int len, int stagger_sum, int high_num, bool limit) {


}

ll solve(ll n) {
    if (n <= 0) return 0;
    ll key = n, t = 1, ret = 0;
    while (key) {
        bits[t++] = key % 10;
        key /= 10;
    }
    t--;
    base[1] = 1;
    for (int i = 2; i < 20; i++) base[i] = base[i - 1] * 10 % mod;
    for (int i = t; i > 0; i--) {
        (ret += dp[i][bits[i] - 1]][k].sum % mod) %= mod;
    }



}


int main(void)
{
#ifdef LOCAL
     freopen("in.txt", "r", stdin);
   //freopen("out.txt", "w", stdout);
#endif
    ll l, r;
    while (cin >> l >> r >> k) {
        memset(dp, -1, sizeof(dp));
        cout << (solve(r) - solve(l - 1) + mod) % mod << endl;
    }
    return 0;
}
