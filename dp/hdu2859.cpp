/**********************jibancanyang**************************
 *Author        :jibancanyang
 *Created Time  : 四  4/ 7 12:45:54 2016
 *File Name     : hdu2859.cpp
 *题目类型:最大对称子矩阵
 *感悟:令dp[i][j],表示以这个格子为矩阵左下角的最大对称矩阵的大小.dp[i][j]就只和dp[i + 1][j + 1],和该格子往上的列往右的行有关了.这类dp的核心是分解子问题,观察性质.这的性质就是以对角线为中心往两边加两条边就可以分解子问题的作用.
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
const int mod = int(1e9) + 7, INF = 0x3fffffff, maxn = 1e3 + 12;
int dp[maxn][maxn];
char a[maxn][maxn];
int n;

bool isit(int x, int y, int t) {
    rep (i, 0, t + 1) {
        rep (j, 0, t - i + 1) {
            int u = x + t - j, v = y + t - i;
            if (a[x + i][y + j] != a[u][v]) return false;

        }
    }
    return true;
}

bool judge(int x, int y, int t) {
    for (int i = 0; i < t; i++) {
        if (a[x][y + i] != a[x + t - i][y]) return false;
    }
    for (int i = 0; i < t; i++) {
        if (a[x + i][y] != a[x + t][y + t - i]) return false;
    }
    return true;
}

int main(void)
{
#ifdef LOCAL
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    cin.sync_with_stdio(false);
    while (cin >> n, n) {
        rep (i, 1, n + 1) {
            rep (j, 1, n + 1) {
                cin >> a[n - i + 1][j];
            }
        }
        int ans = 1;
        rep (j, 1, n + 1) dp[n][j] = 1, dp[j][n] = 1;
        for (int i = n - 1; i > 0; i--) {
            for (int j = n - 1; j >0; j--) {
                int t = dp[i + 1][j + 1];
                int cnt = 1;
                for (int k = 1; i + k <= n && j + k <= n && cnt <= t; k++) {
                    if (a[i + k][j] != a[i][j + k]) break;
                    cnt++;
                }
                dp[i][j] = cnt;
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << endl;

    }
    return 0;
}
