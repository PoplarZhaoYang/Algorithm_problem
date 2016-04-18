/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 二  4/19 00:05:58 2016
 *File Name     : hdu3652.cpp
 *Problem:数位dp经典
 *Get:非常经典的数位dp,用模板化limit dfs的方式写比较直接,状态定义见代码注解.这里发现这样模板化之后,
 *只需要每次都来倒着拆分这个数为数字,然后倒着扩展(还原回去是从左到右扩展),就可以解决连续数字串,固定
 *余数的问题.而且加入的limit让最后的扩展变得非常模板化,十分简洁.试想这个写成递推,会非常繁杂的解决limit问题.
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
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = 13, INF = 0x3fffffff, maxn = 1e5 + 12;
int bit[11], n, dp[11][13][2][2], t, x;

//扩展到第len位, 余数为res, 到目前为止是否有13出现, 上一位是否为1, 本位是否有限制
int dfs(int len, int res, bool have, bool cur, bool limit) {
    //pr(len), pr(res), pr(have), pr(cur), pl(limit);
    if (len == -1) return have && res == 0;
    if (!limit && dp[len][res][have][cur] != -1) return dp[len][res][have][cur];
    int m = limit ? bit[len] : 9;
    int ret = 0;
    for (int i = 0; i <= m; i++) {
        ret += dfs(len - 1, (res * 10 % mod + i) % mod, have || (cur && i == 3), i == 1, limit && i == m);
    }
    if (!limit) dp[len][res][have][cur] = ret;
    return ret;
}

int solve(int n) {
    t = 0, x = n;
    while (x) {
        bit[t++] = x % 10;
        x /= 10;
    }
    return dfs(t - 1, 0, false, false, true);
}

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin.sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    while (cin >> n) {
        cout << solve(n) << endl;
    }
    return 0;
}
