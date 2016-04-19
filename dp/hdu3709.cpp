/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 二  4/19 11:02:24 2016
 *File Name     : hdu3709.cpp
 *Problem:数位dp
 *Get:基本思路还是数位dp模板的,在设置限制的情况下,一位一位的补上去.主要是这里有一个重要的性质,就是支点一边的数的力矩和
最大不会超过1800,这样我们就考虑把所有的位当做支点然后记录目前已经选择的数的力矩和.利用这个性质我们构造一个状态
dp[pos][pivot][pre]表示扩展到第pos位,当前选择的支点是第pivot位,扩展到当前位的力矩和为pre,然后算过的就不用算了,这就是记忆
优化的dp.
这里注意对00000的出理,因为每次枚举一个不同的支点都会算一次000000,所以最后要减去t-1个00000,只保留一个.
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
vector<int> vi;
#define pr(x) cout << #x << ": " << x << "  " 
#define pl(x) cout << #x << ": " << x << endl;
#define xx first
#define yy second<F5>
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e5 + 12;
ll T, l, r, bit[20];
ll dp[20][20][1800];

ll dfs(int pos, int pivot, int pre, bool limit) {
    if (pos == -1) return pre == 0;
    if (pre < 0) return 0;//减枝,到当前已经为负了,后面全是减去,显然不会到0
    if (!limit && dp[pos][pivot][pre] != -1) return dp[pos][pivot][pre];
    ll ret = 0;
    int m = limit ? bit[pos] : 9;
    for (int i = 0; i <= m; i++) {
        ret += dfs(pos - 1, pivot, pre + (pos - pivot) * i, limit && i == m);
    }
    if (!limit) dp[pos][pivot][pre] = ret;
    return ret;
}

ll solve(ll n) {
    ll t = 0, x = n;
    while (x) {
        bit[t++] = x % 10;
        x /= 10;
    }
    ll ret = 0;
    for (int i = 0; i < t; i++) {
       ret += dfs(t - 1, i, 0, true); 
    }
    return ret - t + 1;
}

int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin.sync_with_stdio(false);
    cin >> T;
    memset(dp, -1, sizeof(dp));
    while (T--) {
        cin >> l >> r;
        cout << solve(r) - solve(l - 1) << endl;
    }
    return 0;
}
