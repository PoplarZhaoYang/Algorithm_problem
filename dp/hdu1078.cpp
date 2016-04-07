/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 四  4/ 7 10:08:40 2016
 *File Name     : hdu1078.cpp
 *题目类型:记忆化搜索
 *感悟:这个题的核心就是,从一个点出发走到它无路可走的值是多少,这个是无后效性的所以可以用dp.
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
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++) 
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e5 + 12;
int n, k, dp[102][102], a[102][102];

int dfs(int x, int y, int pre) {
    if (a[x][y] <= pre) return 0;
    if (dp[x][y]) return dp[x][y];
    int ret = a[x][y], ret1 = 0, ret2 = 0, ret3 = 0, ret4 = 0;
    for (int i = 1; i <= k; i++) {
       if (x + i <= n) ret1 = max(ret1, dfs(x + i, y, a[x][y])); 
       if (x - i > 0) ret2 = max(ret2, dfs(x - i, y, a[x][y])); 
       if (y + i <= n) ret3 = max(ret3, dfs(x , y + i, a[x][y])); 
       if (y - i > 0) ret4 = max(ret4, dfs(x , y - i, a[x][y])); 
    }
    
    ret = max(max(ret1, ret2), max(ret3, ret4)) + ret;
    return dp[x][y] = ret;
}
int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin.sync_with_stdio(false);
    while (cin >> n >> k, (n != -1 && k != -1)) {
        rep (i, 1, n + 1) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
                dp[i][j] = 0;
            }
        }
        cout << dfs(1, 1, -INF) << endl;
    }
    return 0;
}
