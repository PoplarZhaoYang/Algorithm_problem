/**********************jibancanyang**************************
 *Author*        :jibancanyang
 *Created Time*  : 二  7/ 5 15:44:46 2016
**Problem**:
**Analyse**:
很容易想到状态定义：$dp[i][j]$，表示前$i$天，有$j$个股票的最大利润。
然后也容易写出转移方程，即使有个隔$w$天，那么隔$w$再转移不就好了。
dp[i][j]必须继承dp[i-1][j]，这是不选的情况，而不是$dp[i - w - 1][j]$。
然后观察状态转移方程部分，找出哪些是常量，哪些是变量，发现需要维护固定区间最大值。
而且是两个，单调队列就好了。
单调队列的节点有两个元素，一个是节点值，一个是节点标号，节点标号在判断逃出的时候有特效。
单调队列的正确性由来：那些比你后加入的节点都比你更优，它们比你更后离开，所以你没有用，表现上就是维护一个单调的队列。
但是那些大的元素，淘汰的方法就是队首判断下标。

**Get**:
分析转移方程来降低维度非常重要。用抽象思维来思考，再把每个抽象体对应到代码。
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
const int maxn = 2e3 + 13;
int dp[maxn][maxn];
pii lque[maxn * 10], rque[maxn * 10];


int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T; sa(T);
    while (T--) {
        int t, maxp, w; sa(t), sa(maxp), sa(w);
        for (int i = 0; i <= maxp; i++) dp[0][i] = -INF;
        dp[0][0] = 0;

        for (int i = 1; i <= t; i++) {
            int api, bpi, asi, bsi; sa(api), sa(bpi), sa(asi), sa(bsi);
            int I = max(0, i - w - 1);
            int  r = 0, l1 = 0, l2 = 0, r1 = 0, r2 = 0;
            for (int j = 0; j <= maxp; j++) {
                while (r <= j + bsi && r <= maxp) {
                    if (dp[I][r] != -INF) {
                        while (l2 < r2 && dp[I][r] + r * bpi > rque[r2 - 1].yy) r2--;
                        rque[r2].xx = r;
                        rque[r2++].yy = dp[I][r] + r * bpi;
                    }
                    r++;
                }
                while (l2 < r2 && rque[l2].xx <= j)  l2++;

                if (j - 1 >= 0 && dp[I][j - 1] != -INF) {
                    while (l1 < r1 && dp[I][j - 1] + (j - 1) * api > lque[r1 - 1].yy) r1--;
                    lque[r1].xx = j - 1;
                    lque[r1++].yy = dp[I][j - 1] + (j - 1) * api;
                }
                while (l1 < r1 && lque[l1].xx < j - asi) l1++;
                dp[i][j] = max(dp[i - 1][j], max(l2 == r2 ? -INF : rque[l2].yy - j * bpi, l1 == r1 ? -INF : lque[l1].yy - j * api));
            }
        }
        int ans = 0;
        for (int i = 0; i <= maxp; i++) {
            ans = max(ans, dp[t][i]);
        }
        pri(ans);
    }
    return 0;
}

