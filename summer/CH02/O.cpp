
/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 三  7/ 6 16:11:13 2016
**Problem**:
**Analyse**:
二维棋盘随机放置，覆盖所有行列的期望天数。经典概率dp
定义$dp[i][j]$为已经出现$i$种，有$j$个系统的期望天数。
那么它是由它的四个子结果的期望天数的加权平均 + 1 天。
这里的加权平均的权是各自的概率。
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
double dp[1009][1009];



int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int n, s;
    while (~scanf("%d%d", &n, &s)) {
        memset(dp, 0, sizeof(dp));
        dp[n][s] = 0;
        for (int i = n; i >= 0; i--) {
            for (int j = s; j >= 0; j--) {
                if (i == n && j == s) continue;
                dp[i][j] = (
                     dp[i + 1][j] * (n - i) * j  + 
                     n * s  +
                     dp[i][j + 1] * i * (s - j)  + 
                     dp[i + 1][j + 1] * (n - i) * (s - j) ) 
                    / (n * s - i * j);
            }
        }
        printf("%.4f\n", dp[0][0]);
    }

    return 0;
}
