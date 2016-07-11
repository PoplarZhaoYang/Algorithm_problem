/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 一  7/11 21:49:09 2016
**Problem**:
**Analyse**:
这里先分析数据范围和时间，可以给出很暴力的指数级别的算法。
比如状态压缩dp。
定义$dp[s]$为当前选择状态为$s$，到选完后选手最多比后手多的宝石个数。
$dp[0]=0$$，没有宝石了。
然后从$00000$，一直逆推到$11111$即可，每一步暴力的选择任意的数。
复杂度$2^B*B*G$，$G$的复杂度来自于维护宝石个数。
**Get**:
这种最优选择问题，在状态定义时，直接定义了状态为最优，非常技巧。
从我们开始知道什么，来得出递推顺序也很重要。
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
int G, B, S;
int bag[22][11];
int dp[1 << 21][11];



int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    while (sa(G), sa(B), sa(S), G || B || S) {
        int a[11], maxs = (1 << B) - 1;
        memset(bag, 0, sizeof(bag));
        memset(a, 0, sizeof(a));
        for (int i = 0; i < B; i++) {
            int n; sa(n);
            while (n--) {
                int x; sa(x);
                bag[i][x]++;
                a[x]++;
                a[x] %= S;
            }
        }
        dp[0][0] = 0;
        for (int i = 1; i <= G; i++) dp[0][i] = a[i];
        for (int i = 1; i <= maxs; i++) dp[i][0] = -INF;
        for (int i = 0; i < maxs; i++) {
            for (int j = 0; j < B; j++) {
                int t = (1 << j);
                if (i & t) ;
                else {
                    int ruby = 0;
                    for (int k = 1; k <= G; k++) {
                        a[k] = dp[i][k] - bag[j][k];
                        while (a[k] < 0) {
                            a[k] += S;
                            ruby++;
                        }
                        dp[i ^ t][k] = a[k];
                    }
                    if (ruby > 0) {
                        dp[i ^ t][0] = max(dp[i ^ t][0], ruby + dp[i][0]);
                    } else {
                        dp[i ^ t][0] = max(dp[i ^ t][0], -dp[i][0]);
                    }
                }
            }
        }
        pri(dp[maxs][0]);
    }
    return 0;
}
