#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
vector<int> vi;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
#define limit asdf
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e5 + 12;
int T;
ll dp[19][4][9876 + 7][5];
int bits[25];
ll l, r;
int k;

ll dfs(int len, int ban, bool limit, int k, int go, int zero, bool pre) {
    if (len == 0) return 1;
    if (!pre && !limit && dp[len][k - 2][ban][zero] != -1) return dp[len][k - 2][ban][zero];
    int m = limit ? bits[len] : 9;

   // baned
    //cout << endl;
    ll ret = 0;
    bool no[10];
    memset(no, 0, sizeof(no));
    int t = ban;
   // pr(pre), pr(zero), pr(len), pl(ban);
    for (int i = 0; t; ++i) {
        no[t % 10] = true;
        t /= 10;
    }
    if (!pre && zero > 0) no[0] = true;
    //cout << endl;
    
    //longer
    for (int i = 0; i <= m; i++) {
        if (no[i]) continue;
        int nxt = ban % (int)pow(10, k - 2); 
        nxt = nxt * 10 + i;
        int nxtzero = zero;
        if (!pre) {
            if (!i) nxtzero = k - 1;
            else nxtzero--;
            if (nxtzero < 0) nxtzero = 0;
        } 
        //pl(i);
        ret += dfs(len - 1, nxt, limit && i == m, k, go + 1, nxtzero, pre && !i);
    }
    if (!pre && !limit) dp[len][k - 2][ban][zero] = ret;
    return ret;
}

ll solve(ll n) {
    ll key = n, t = 1;
    while (key) {
        bits[t++] = key % 10;
        key /= 10;
    }
    ll ret = dfs(t - 1, 0, true, k, 0, 0, true);
    return ret;
}


int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
   // freopen("out.txt", "w", stdout);
#endif
    memset(dp, -1, sizeof(dp));
    while (~scanf("%lld%lld%d", &l, &r, &k)) {
        printf("%lld\n", solve(r) - solve(l - 1));
    }
    return 0;
}
