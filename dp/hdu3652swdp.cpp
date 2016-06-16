/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 四  6/16 21:00:50 2016
**Problem**:
**Analyse**:
**Get**:
**Code**:
***********************1599664856@qq.com**********************/

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
typedef vector<int> vi;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;
#define pri(a) printf("%d\n",(a))
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define sal(n) scanf("%lld", &(n))
#define sai(n) scanf("%I64d", &(n))
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f;
const int maxn = 1e5 + 13;

int bits[11];
int dp[11][10][2][13];

int dfs(int len, int high, bool have, bool limit, int res) {
    if (len == 0) {
        return !have && (res == 0);
    }
    if (!limit && dp[len][high][have][res] != -1) return dp[len][high][have][res];

    int m = limit ? bits[len] : 9;
    int ret = 0;
    for (int i = 0; i <= m; i++) {
        if ( (high == 1 && i  == 3) || !have ) ret += dfs(len - 1, i, false, limit && i == m, (res * 10 + i) % 13 );
        else  ret += dfs(len - 1, i, true, limit && i == m, (res * 10 + i) % 13);
    }
    if (!limit) dp[len][high][have][res] = ret;
    return ret;
}


int solve(int n) {
    int t = 1;
    while (n) {
        bits[t++] = n % 10;
        n /= 10;
    }
    bits[t] = 9;
    return dfs(t - 1, 9, true, true, 0);
}

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int r;
    memset(dp, -1, sizeof(dp));
    while (~sa(r)) {
        pri(solve(r));
    }
    return 0;
}
